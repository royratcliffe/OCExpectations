// OCExpectations OCExpectationsTests.m
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

#import "OCExpectationsTests.h"

#import <OCExpectations/OCExpectations.h>

@implementation OCExpectationsTests

- (void)testShouldEqualNoThrow
{
	// 1 + 1 should = 2
	STAssertNoThrow([@(1 + 1) should:[@2 equal]], nil);
}

- (void)testShouldEqualThrows
{
	// 1 should NOT = 2
	STAssertThrows([@1 should:[@2 equal]], nil);
}

- (void)testShouldBeTrue
{
	STAssertNoThrow([@YES should:[@YES be]], nil);
	STAssertThrows([@NO should:[@YES be]], nil);
}

- (void)testShouldBeFalse
{
	STAssertNoThrow([@NO should:[@NO be]], nil);
	STAssertThrows([@YES should:[@NO be]], nil);
}

@end
