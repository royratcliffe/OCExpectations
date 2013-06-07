// OCFoundation OCRecursiveEnumeration.m
//
// Copyright © 2012, Roy Ratcliffe, Pioneering Software, United Kingdom
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the “Software”), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
//	The above copyright notice and this permission notice shall be included in
//	all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED “AS IS,” WITHOUT WARRANTY OF ANY KIND, EITHER
// EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
// EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
// OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//
//------------------------------------------------------------------------------

#import "OCRecursiveEnumeration.h"

@interface OCRecursiveEnumeration()

@property(assign, NS_NONATOMIC_IOSONLY) SEL subSelector;
@property(strong, NS_NONATOMIC_IOSONLY) NSMutableArray *objects;
@property(copy, NS_NONATOMIC_IOSONLY) BOOL (^inclusiveBlock)(id object);

@end

@implementation OCRecursiveEnumeration

- (id)initWithSuperObject:(id)object
		 usingSubSelector:(SEL)selector
				inclusive:(BOOL)inclusive
		   inclusiveBlock:(BOOL (^)(id object))block
{
	if ((self = [super init]))
	{
		self.subSelector = selector;
		self.objects = [NSMutableArray array];
		self.inclusiveBlock = block;
		if (inclusive)
		{
			[self.objects addObject:object];
		}
		else
		{
			[self.objects addObjectsFromArray:[object performSelector:self.subSelector]];
		}
	}
	return self;
}

- (NSUInteger)countByEnumeratingWithState:(NSFastEnumerationState *)state
								  objects:(__unsafe_unretained id[])buffer
									count:(NSUInteger)len
{
	NSUInteger count = 0;
	
	if (state->state == 0)
	{
		state->mutationsPtr = state->extra;
	}
	
	while (state->state < self.objects.count && count < len)
	{
		id object = [self.objects objectAtIndex:state->state++];
		if (self.inclusiveBlock == NULL || self.inclusiveBlock(object))
		{
			[self.objects addObjectsFromArray:[(buffer[count++] = object) performSelector:self.subSelector]];
		}
	}
	state->itemsPtr = buffer;
	
	// Pop off spent objects from the front of the mutable array. Is this an
	// efficient stack implementation? Will NSMutableArray always copy? Even if
	// so, the number of object pointers in the array will always be relatively
	// small. After the popping, state will remain greater than zero.
	if (state->state > len)
	{
		[self.objects removeObjectsInRange:NSMakeRange(0, len)];
		state->state -= len;
	}
	
	return count;
}

@end
