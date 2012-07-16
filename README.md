# Objective-C Expectations

The OCExpectations project provides a library of Objective-C expectation matchers styled after [RSpec](http://rspec.info/) expectations. Expressing an expectation in Ruby as

```ruby
5.should equal(5)
```

becomes

```objc
[@5 should:[@5 equal]]
```

in Objective-C. Very similar albeit in a somewhat Shakespearean form of words. Or perhaps [Yoda-speak](http://www.yodaspeak.co.uk/index.php) would be a better explanation; although _he_ would more likely say, "equal 5, 5 should!"

You can easily expand on the library by adding your own matchers.

### OC Stands for Objective-C

The `OC` namespace stands for Objective-C of course but it carries additional significance. This choice reflects the project goals of cross platform support and open-source community responsibility. The `info.rspec.OCExpectations` bundle identifier echoes the same aspiration.

