// OCExpectations NSObject+OCSpecMatchers.h
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

#import <Foundation/Foundation.h>

@protocol OCSpecMatcher;

/*!
 * To obtain a matcher, send one of the following messages to the expected
 * value. The expected value must always be an object. With LLVM 4.0, you can
 * conveniently convert literals to Objective-C objects.
 */
@interface NSObject(OCSpecMatchers)

- (id<OCSpecMatcher>)be;
- (id<OCSpecMatcher>)beAKindOf;
- (id<OCSpecMatcher>)equal;

@end

#ifndef be
#define be(expected) [(expected) be]
#endif

#ifndef beAKindOf
#define beAKindOf(expected) [(expected) beAKindOf]
#endif

#ifndef equal
#define equal(expected) [(expected) equal]
#endif
