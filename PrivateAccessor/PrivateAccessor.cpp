// PrivateAccessor.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Accessor.h"
#include "TargetClass.h"

struct Accessor_TargetClass_Member1 { typedef int TargetClass::* type; };
template struct Initializer<Accessor_TargetClass_Member1, &TargetClass::member1_>;

struct Accessor_TargetClass_Member2 { typedef int TargetClass::* type; };
template struct Initializer<Accessor_TargetClass_Member2, &TargetClass::member2_>;

struct Accessor_TargetClass_Method1 { typedef int (TargetClass::*type)(int); };
template struct Initializer<Accessor_TargetClass_Method1, &TargetClass::Method1>;

struct Accessor_TargetClass_Method2 { typedef int (TargetClass::*type)(int); };
template struct Initializer<Accessor_TargetClass_Method2, &TargetClass::Method2>;

int main()
{
  TargetClass target(1, 2);

  std::cout << target.*Accessor<Accessor_TargetClass_Member1>::ptr_ << std::endl;
  std::cout << target.*Accessor<Accessor_TargetClass_Member2>::ptr_ << std::endl;

  target.*Accessor<Accessor_TargetClass_Member1>::ptr_ = 3;
  target.*Accessor<Accessor_TargetClass_Member2>::ptr_ = 4;

  target.Print();
  // std::cout> member1 = 3, member2 = 4

  std::cout << (target.*Accessor<Accessor_TargetClass_Method1>::ptr_)(1) << std::endl;
  std::cout << (target.*Accessor<Accessor_TargetClass_Method2>::ptr_)(2) << std::endl;

  target.Print();
  // std::cout> member1 = 4, member2 = 6

  return 0;
}

