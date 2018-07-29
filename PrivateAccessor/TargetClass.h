#pragma once

#include <iostream>

class TargetClass
{
public:
  TargetClass(const int a, const int b)
    : member1_(a), member2_(b) {
  }

  virtual ~TargetClass() {
  }

  void Print() {
    std::cout << "member1 = " << member1_ << ", member2 = " << member2_ << std::endl;
  }

protected:
  int member1_;
  int Method1(int a) {
    member1_ += a;
    std::cout << "member1 = " << member1_ << std::endl;
    return member1_;
  }

private:
  int member2_;
  int Method2(int a) {
    member2_ += a;
    std::cout << "member2 = " << member2_ << std::endl;
    return member2_;
  }
};
