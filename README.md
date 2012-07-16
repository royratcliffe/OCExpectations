# Objective-C Expectations

The OCExpectations project provides a library of Objective-C expectation matchers styled after [RSpec](http://rspec.info/) expectations. Expressing an expectation in Ruby as

```ruby
5.should equal(5)
```

becomes

```objc
[@5 should:[@5 equal]]
```

in Objective-C. Very similar albeit in a somewhat Shakespearean form of words. Or perhaps [Yoda-speak](http://www.yodaspeak.co.uk/index.php) would be a better analogy; although _he_ would more likely say, "equal 5, 5 should!" Nevertheless, Objective-C's receiver-message syntax dictates the ordering. The `-should:aMatcher` message describes a positive expectation while `-equal` specifies the equality matcher. The above example makes use of the [Objective-C literal](http://clang.llvm.org/docs/ObjectiveCLiterals.html) syntax available in the [LLVM](http://llvm.org/) version 4.0 compiler bundled with Xcode 4.4 and above. You consequently need LLVM version 4.0 as a minimum requirement.

You can easily expand on the library by adding your own matchers.

### OC Stands for Objective-C

The `OC` namespace stands for Objective-C of course but it carries additional significance. This choice reflects the project goals of cross platform support and open-source community responsibility. The `info.rspec.OCExpectations` bundle identifier echoes the same aspiration.

