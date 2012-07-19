// OCExpectations OCHelpers.h
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

/*!
 * @brief Negates a boolean or nil; not nil answering YES.
 * @details In Ruby, false equals nil or false. Therefore negating nil answers
 * true just as negating false answers true. Translating this logic to
 * Objective-C, negating NO or nil answers YES; negating YES answers NO. Ignore
 * NSNull for now; although NSNull stands for nil for user interface components.
 */
NSNumber *OCSpecNotBool(NSNumber *boolOrNil);

/*!
 * @brief Negates an object or nil.
 * @details In Ruby, you can also negate arbitrary object references answering
 * false if not nil, true if nil. Imitate this behaviour by negating as a
 * boolean for nil or NSNumbers, but answer NO for any other kind. Treat all
 * NSNumbers as booleans.
 */
NSNumber *OCSpecNot(id objectOrNil);
