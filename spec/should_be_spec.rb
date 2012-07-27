describe "math" do
  it "should add" do
    (1+1).should be(2)
    0.5.should be_within(0.5)
    [1, 2, 3].should include(2)
  end
end