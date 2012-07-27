// OCExpectations OCSpecIncludeMatcher.m
//
// Copyright © 2012, The OCCukes Organisation. All rights reserved.
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

#import "OCSpecIncludeMatcher.h"

@implementation OCSpecIncludeMatcher

- (id)matches:(id)actual
{
	id match = nil;
	actual = [super matches:actual];
	if ([actual isKindOfClass:[NSDictionary class]])
	{
		NSArray *actualKeys = [(NSDictionary *)actual allKeys];
		if ([self.expected isKindOfClass:[NSDictionary class]])
		{
			NSArray *expectedKeys = [(NSDictionary *)self.expected allKeys];
			if ([[NSSet setWithArray:expectedKeys] isSubsetOfSet:[NSSet setWithArray:actualKeys]])
			{
				NSArray *actuals = [(NSDictionary *)actual objectsForKeys:expectedKeys notFoundMarker:[NSNull null]];
				NSArray *expecteds = [(NSDictionary *)self.expected objectsForKeys:expectedKeys notFoundMarker:[NSNull null]];
				match = @([actuals isEqualToArray:expecteds]);
			}
			else
			{
				match = @NO;
			}
		}
		else
		{
			NSArray *expectedKeys = [self.expected isKindOfClass:[NSArray class]] ? self.expected : [NSArray arrayWithObject:self.expected];
			match = @([[NSSet setWithArray:expectedKeys] isSubsetOfSet:[NSSet setWithArray:actualKeys]]);
		}
	}
	else
	{
		NSArray *actuals = [actual isKindOfClass:[NSArray class]] ? actual : [NSArray arrayWithObject:actual];
		NSArray *expecteds = [self.expected isKindOfClass:[NSArray class]] ? self.expected : [NSArray arrayWithObject:self.expected];
		match = @([[NSSet setWithArray:expecteds] isSubsetOfSet:[NSSet setWithArray:actuals]]);
	}
	return match;
}

@end
