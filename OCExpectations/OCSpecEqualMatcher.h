// OCExpectations OCSpecEqualMatcher.h
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

#import <OCExpectations/OCSpecBaseMatcher.h>

/*!
 * @details Equal matching has Objective-C semantics, not Ruby semantics. In
 * other words, although in Ruby `"5".should_not equal("5")`, not so in
 * Objective-C. `[@"5" should:[@"5" equal]]` because the equal matcher sends
 * `-[NSObject isEqual:]`. The `isEqual:anObject` method belongs to the standard
 * NSObject protocol where equality does not mean equal identity. Rather, it
 * means equal value.
 */
@interface OCSpecEqualMatcher : OCSpecBaseMatcher

@end
