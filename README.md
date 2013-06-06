# ![Cucumber Roll](http://files.softicons.com/download/object-icons/richs-misc-icons-by-rich-d/png/24/Cucumber%20Roll.png) Objective-C Expectations

[![Build Status](https://travis-ci.org/royratcliffe/OCExpectations.png?branch=master)](https://travis-ci.org/royratcliffe/OCExpectations)

The OCExpectations project provides a library of Objective-C expectation matchers styled after [RSpec](http://rspec.info/) expectations. Expressing an expectation in Ruby RSpec as

```ruby
5.should equal(5)
```

becomes

```objc
[@5 should:[@5 equal]]
```

in Objective-C. Very similar albeit in a somewhat Shakespearean form of words. Or perhaps [Yoda-speak](http://www.yodaspeak.co.uk/index.php) would be a better analogy; although _he_ would more likely say, "equal 5, 5 should!" Nevertheless, Objective-C's receiver-message syntax dictates the ordering. The `-should:aMatcher` message describes a positive expectation while `-equal` specifies the equality matcher.

### To be or not to be?

Does this improve over using C functions and macros for matchers?

Yes with respect to namespaces. The project could define a pre-processor macro, or function, so that your expectation would read `[@5 should:equal(@5)]` for example. Trouble is, Objective-C has no namespace or module support. The matcher macros would consequently live in the global namespace and potentially clash with other projects including your own. What if your project defines `equal`? Adding a namespace prefix, as is convention, would work around that issue. But `[@5 should:OCSpecEqual(@5)]` looses something in readability.

The same applies to some extent with the expectation interface, `-[NSObject should:aMatcher]`. This polutes the `NSObject` space. What if your project defines that method on `NSObject` or one of its subclasses? [Trouble at mill](http://www.urbandictionary.com/define.php?term=trouble%20at%20the%20mill)!

As a compromise, OCExpectations hash-defines a set of corresponding C pre-processor macros _if and only if_ not already defined. So if your or some other included project defines `be` then you _cannot_ use `be(@5)` and have to use `[@5 be]`. Provided that you import `<OCExpectations/OCExpectations.h>` at the very end of your list of imports, then namespace collisions will never occur _and_ you can enjoy the more natural form of expression:

```objc
[@5 should:equal(@5)]
```

### Literals and boxed expressions

The above example makes use of the [Objective-C literal](http://clang.llvm.org/docs/ObjectiveCLiterals.html) syntax available in the [LLVM](http://llvm.org/) version 4.0 compiler bundled with Xcode 4.4 and above. You consequently need LLVM version 4.0 as a minimum requirement, as the project source code makes full use of literals and boxed expressions.

### Custom matchers

You can easily expand on the library by adding your own matchers.

### OC Stands for Objective-C

The `OC` namespace stands for Objective-C of course but it carries additional significance. This choice reflects the project goals of cross platform support and open-source community responsibility. The `info.rspec.OCExpectations` bundle identifier echoes the same aspiration.

## MIT Licensing

Copyright © 2012, The OCCukes Organisation. All rights reserved.

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the “Software”), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in
	all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED “AS IS,” WITHOUT WARRANTY OF ANY KIND, EITHER
EXPRESSED OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NON-INFRINGEMENT. IN NO
EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES
OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,
ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
DEALINGS IN THE SOFTWARE.

## Sponsors

- Levide Capital Limited, Blenheim, New Zealand

## Contributors

- Roy Ratcliffe, Pioneering Software, United Kingdom
