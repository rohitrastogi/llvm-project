//===----------------------------------------------------------------------===//
//
// Part of the LLVM Project, under the Apache License v2.0 with LLVM Exceptions.
// See https://llvm.org/LICENSE.txt for license information.
// SPDX-License-Identifier: Apache-2.0 WITH LLVM-exception
//
//===----------------------------------------------------------------------===//

// <system_error>

// class error_code

// template <class charT, class traits>
//   basic_ostream<charT,traits>&
//   operator<<(basic_ostream<charT,traits>& os, const error_code& ec);

#include <system_error>
#include <sstream>
#include <cassert>

int main()
{
    std::ostringstream out;
    out << std::error_code(std::io_errc::stream);
    assert(out.str() == "iostream:1");
}
