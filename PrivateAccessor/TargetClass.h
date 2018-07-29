#pragma once

#include <iostream>
#include <string>

class BaseClass {
public:
  BaseClass() {
  }

  virtual ~BaseClass() {
  }

  void Method3(const std::string& c) {
    member3_ += c;
    std::cout << "member3 = " << member3_ << std::endl;
  }

  void BasePrint() {
    std::cout << "member3 = " << member3_ << std::endl;
  }

private:
  std::string member3_;

  virtual int Method2(const int a) {
    std::cout << "BaseClass::Method2 method called." << std::endl;
    return 0;
  }
};

class TargetClass : public BaseClass {
public:
  TargetClass(const int a, const int b)
    : member1_(a), member2_(b) {
  }

  virtual ~TargetClass() {
  }

  void Print() {
    std::cout << "member1 = " << member1_ << ", member2 = " << member2_ << ", member4 = " << member4_ << std::endl;
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
  virtual int Method2(const int a) {
    member2_ += a;
    std::cout << "member2 = " << member2_ << std::endl;
    return member2_;
  }

  static int member4_;
  static int Method4(const int a) {
    member4_ += a;
    std::cout << "member4 = " << member4_ << std::endl;
    return member4_;
  }
};
