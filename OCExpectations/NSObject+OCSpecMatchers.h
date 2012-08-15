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

@class OCSpecBeWithinMatcher;

/*!
 * To obtain a matcher, send one of the following messages to the expected
 * value. The expected value must always be an object. With LLVM 4.0, you can
 * conveniently convert literals to Objective-C objects.
 */
@interface NSObject(OCSpecMatchers)

+ (id<OCSpecMatcher>)beTrue;
+ (id<OCSpecMatcher>)beFalse;
+ (id<OCSpecMatcher>)beNull;

- (id<OCSpecMatcher>)be;
- (id<OCSpecMatcher>)beA;
- (id<OCSpecMatcher>)beAn;
- (id<OCSpecMatcher>)beAnInstanceOf;
- (id<OCSpecMatcher>)beInstanceOf;
- (id<OCSpecMatcher>)beAKindOf;
- (id<OCSpecMatcher>)beKindOf;
- (OCSpecBeWithinMatcher *)beWithin;

- (id<OCSpecMatcher>)equal;
- (id<OCSpecMatcher>)eql;

- (id<OCSpecMatcher>)include;

- (id<OCSpecMatcher>)compareSame;

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

#ifndef be_null
#define be_null [NSObject beNull]
#endif

#ifndef be
#define be(expected) [(expected) be]
#endif

#ifndef be_a
#define be_a(expected) [(expected) beA]
#endif

#ifndef be_an
#define be_an(expected) [(expected) beAn]
#endif

#ifndef be_an_instance_of
#define be_an_instance_of(expected) [(expected) beAnInstanceOf]
#endif

#ifndef be_instance_of
#define be_instance_of(expected) [(expected) beInstanceOf]
#endif

#ifndef be_a_kind_of
#define be_a_kind_of(expected) [(expected) beAKindOf]
#endif

#ifndef be_kind_of
#define be_kind_of(expected) [(expected) beKindOf]
#endif

#ifndef be_within
#define be_within(expected) [(expected) beWithin]
#endif

#ifndef equal
#define equal(expected) [(expected) equal]
#endif

#ifndef eql
#define eql(expected) [(expected) eql]
#endif

#ifndef include
#define include(expected) [(expected) include]
#endif

#ifndef compare_same
#define compare_same(expected) [(expected) compareSame]
#endif
