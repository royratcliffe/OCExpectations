// OCExpectations OCSpecIncludeMatcher.h
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

#import <OCExpectations/OCExpectations.h>

/*!
 * @brief Answers @YES if the matcher's actual includes the expected; otherwise
 * answers @NO.
 * @details Arrays and dictionaries (hashes) may appear at either side of the
 * matching equation, as an actual or expected value. You can compare two
 * hashes. Hashes match if the expected keys form a subset of the actual keys
 * and their values also match. You can match a hash against an array. The array
 * describes expected keys; values do not matter.
 */
@interface OCSpecIncludeMatcher : OCSpecBaseMatcher

@end
