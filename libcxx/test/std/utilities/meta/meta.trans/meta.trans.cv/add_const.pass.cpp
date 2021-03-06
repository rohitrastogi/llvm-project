//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// type_traits

// add_const

#include <type_traits>

#include "test_macros.h"

template <class T, class U>
void test_add_const_imp()
{
    static_assert((std::is_same<typename std::add_const<T>::type, const U>::value), "");
#if TEST_STD_VER > 11
    static_assert((std::is_same<std::add_const_t<T>, U>::value), "");
#endif
}

template <class T>
void test_add_const()
{
    test_add_const_imp<T, const T>();
    test_add_const_imp<const T, const T>();
    test_add_const_imp<volatile T, volatile const T>();
    test_add_const_imp<const volatile T, const volatile T>();
}

int main()
{
    test_add_const<void>();
    test_add_const<int>();
    test_add_const<int[3]>();
    test_add_const<int&>();
    test_add_const<const int&>();
    test_add_const<int*>();
    test_add_const<const int*>();
}
