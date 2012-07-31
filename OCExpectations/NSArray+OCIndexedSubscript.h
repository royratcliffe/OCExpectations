// OCExpectations NSArray+OCIndexedSubscript.h
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

// Adds Objective-C subscripting support, if the compiler has the subscripting
// feature. The Foundation framework includes this support automatically in
// later versions, specifically iOS 6.0's Foundation framework where it appears
// in the NSExtendedArray category on NSArray. But iOS 5.1 does not include
// these methods on NSArray. Same goes for OS X 10.7 versus 10.8; it appears in
// the later but not in the former. Unfortunately, you cannot easily or directly
// determine whether the Foundation framework does or does not define these
// methods. Instead, rely on the availability macros.
// See http://clang.llvm.org/docs/ObjectiveCLiterals.html for details.
#if __IPHONE_5_1 <= __IPHONE_OS_VERSION_MAX_ALLOWED && __has_feature(objc_subcripting)
#define OC_SPEC_EXTENDS_NS_ARRAY_INDEXED_SUBSCRIPT 1
#else
#define OC_SPEC_EXTENDS_NS_ARRAY_INDEXED_SUBSCRIPT 0
#endif

#if OC_SPEC_EXTENDS_NS_ARRAY_INDEXED_SUBSCRIPT

@interface NSArray(OCIndexedSubscript)

- (id)objectAtIndexedSubscript:(NSUInteger)index;

@end

#endif
