// OCExpectations OCPositiveExpectationHandler.m
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

#import "OCPositiveExpectationHandler.h"
#import "OCMatcher.h"

@implementation OCPositiveExpectationHandler

- (id)handleActual:(id)actual matcher:(OCMatcher *)matcher
{
	// Fails unless the matcher answers YES. Fails therefore if the matcher answers NO or nil.
	id match = [matcher matches:actual];
	if (match && [match isKindOfClass:[NSNumber class]] && [(NSNumber *)match boolValue])
	{
		return match;
	}
	[[NSException exceptionWithName:@"OCExpectationNotMetError" reason:[matcher failureMessageForShould] userInfo:nil] raise];
	return nil;
}

@end
