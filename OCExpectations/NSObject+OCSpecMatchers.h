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

+ (id<OCSpecMatcher>)beTrue;
+ (id<OCSpecMatcher>)beFalse;
+ (id<OCSpecMatcher>)beNil;

- (id<OCSpecMatcher>)be;
- (id<OCSpecMatcher>)beAKindOf;
- (id<OCSpecMatcher>)equal;

@end

/*
 * Macros use the underscore rather than camel-case delimiter style. This by
 * design because the matcher method extensions use camel-case. Clashes could
 * result if both use the same style. The C pre-processor operates on all
 * tokens, including Objective-C method names.
 */

#ifndef be_true
#define be_true [NSObject beTrue]
#endif

#ifndef be_false
#define be_false [NSObject beFalse]
#endif

#ifndef be_nil
#define be_nil [NSObject beNil]
#endif

#ifndef be
#define be(expected) [(expected) be]
#endif

#ifndef equal
#define equal(expected) [(expected) equal]
#endif

#ifndef be_a_kind_of
#define be_a_kind_of(expected) [(expected) beAKindOf]
#endif
