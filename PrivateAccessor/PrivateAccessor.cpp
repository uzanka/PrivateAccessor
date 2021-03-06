// PrivateAccessor.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Accessor.h"
#include "TargetClass.h"

int TargetClass::member4_ = 0;

struct Accessor_TargetClass_Member1 { typedef int TargetClass::* type; };
template struct Initializer<Accessor_TargetClass_Member1, &TargetClass::member1_>;

struct Accessor_TargetClass_Member2 { typedef int TargetClass::* type; };
template struct Initializer<Accessor_TargetClass_Member2, &TargetClass::member2_>;

struct Accessor_TargetClass_Method1 { typedef int (TargetClass::*type)(int); };
template struct Initializer<Accessor_TargetClass_Method1, &TargetClass::Method1>;

struct Accessor_TargetClass_Method2 { typedef int (TargetClass::*type)(const int); };
template struct Initializer<Accessor_TargetClass_Method2, &TargetClass::Method2>;

struct Accessor_TargetClass_Member3 { typedef std::string BaseClass::* type; };
template struct Initializer<Accessor_TargetClass_Member3, &BaseClass::member3_>;

struct Accessor_TargetClass_Method3 { typedef void (BaseClass::*type)(const std::string&); };
template struct Initializer<Accessor_TargetClass_Method3, &BaseClass::Method3>;

struct Accessor_TargetClass_Member4 { typedef int* type; };
template struct Initializer<Accessor_TargetClass_Member4, &TargetClass::member4_>;

struct Accessor_TargetClass_Method4 { typedef int (*type)(const int); };
template struct Initializer<Accessor_TargetClass_Method4, &TargetClass::Method4>;

int main()
{
  TargetClass target(1, 2);

  std::cout << target.*Accessor<Accessor_TargetClass_Member1>::ptr_ << std::endl;  // std::cout> "1"
  std::cout << target.*Accessor<Accessor_TargetClass_Member2>::ptr_ << std::endl;  // std::cout> "2"

  target.*Accessor<Accessor_TargetClass_Member1>::ptr_ = 3;
  target.*Accessor<Accessor_TargetClass_Member2>::ptr_ = 4;
  *Accessor<Accessor_TargetClass_Member4>::ptr_ = 5;

  target.Print();
  // std::cout> "member1 = 3, member2 = 4, member4 = 5"

  std::cout << (target.*Accessor<Accessor_TargetClass_Method1>::ptr_)(1) << std::endl;  // std::cout> "4"
  std::cout << (target.*Accessor<Accessor_TargetClass_Method2>::ptr_)(2) << std::endl;  // std::cout> "6"
  std::cout << (*Accessor<Accessor_TargetClass_Method4>::ptr_)(3) << std::endl;  // std::cout> "8"
 
  target.Print();
  // std::cout> "member1 = 4, member2 = 6, member = 8"

  // access to base class.
  std::cout << target.*Accessor<Accessor_TargetClass_Member3>::ptr_ << std::endl;  // std::cout> ""

  target.*Accessor<Accessor_TargetClass_Member3>::ptr_ = "abc";

  target.BasePrint();
  // std::cout> "member3 = abc"

  (target.*Accessor<Accessor_TargetClass_Method3>::ptr_)("xyz");  // std::cout> "abcxyz"

  return 0;
}

