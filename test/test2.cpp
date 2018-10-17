/*
 * Copyright (C) 2018 Caian Benedicto <caianbene@gmail.com>
 *
 * This file is part of w1c.
 *
 * w1c is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2, or (at your option)
 * any later version.
 *
 * w1c is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with GNU Make; see the file COPYING.  If not, write to
 * the Free Software Foundation, 675 Mass Ave, Cambridge, MA 02139, USA.
 */

#include <w1c/to.hpp>
#include <iostream>
#include <limits>
#include <stdint.h>

/**
 * Test the conversion of a value with a given type
 * to several other types.
 *
 * @tparam T The type of the value that will be converted.
 *
 * @param value The value that will be converted.
 */
template <typename T>
void test(const T& value)
{
    double    dvalue;
    float     fvalue;
    int64_t   lvalue;
    int32_t   ivalue;
    int16_t   svalue;
    int8_t    cvalue;
    uint64_t ulvalue;
    uint32_t uivalue;
    uint16_t usvalue;
    uint8_t  ucvalue;

    dvalue = w1c::to<double>(value);
    fvalue = w1c::to<float>(value);
    lvalue = w1c::to<int64_t>(value);
    ivalue = w1c::to<int32_t>(value);
    svalue = w1c::to<int16_t>(value);
    cvalue = w1c::to<int8_t>(value);
    ulvalue = w1c::to<uint64_t>(value);
    uivalue = w1c::to<uint32_t>(value);
    usvalue = w1c::to<uint16_t>(value);
    ucvalue = w1c::to<uint8_t>(value);

    std::cout
        <<  dvalue << std::endl
        <<  fvalue << std::endl
        <<  lvalue << std::endl
        <<  ivalue << std::endl
        <<  svalue << std::endl
        <<  cvalue << std::endl
        << ulvalue << std::endl
        << uivalue << std::endl
        << usvalue << std::endl
        << ucvalue << std::endl;
}

/**
 * Program entrypoint.
 *
 * @param argc The number of arguments passed to the program.
 * @param argv The array of arguments passed to the program.
 *
 * @return The exit code of the program
 */
int main(int argc, const char* argv[])
{
    (void)argc;
    (void)argv;

    double    dvalue = 1.0/3.0;
    float     fvalue = 1.0f/3.0f;
    int64_t   lvalue = std::numeric_limits<int64_t >::min();
    int32_t   ivalue = std::numeric_limits<int32_t >::min();
    int16_t   svalue = std::numeric_limits<int16_t >::min();
    int8_t    cvalue = std::numeric_limits<int8_t  >::min();
    uint64_t ulvalue = std::numeric_limits<uint64_t>::max();
    uint32_t uivalue = std::numeric_limits<uint32_t>::max();
    uint16_t usvalue = std::numeric_limits<uint16_t>::max();
    uint8_t  ucvalue = std::numeric_limits<uint8_t >::max();

    test( dvalue); // Expected  9 warnings
    test( fvalue); // Expected  8 warnings
    test( lvalue); // Expected  8 warnings
    test( ivalue); // Expected  5 warnings
    test( svalue); // Expected  2 warnings
    test( cvalue); // Expected  0 warnings
    test(ulvalue); // Expected  8 warnings
    test(uivalue); // Expected  5 warnings
    test(usvalue); // Expected  2 warnings
    test(ucvalue); // Expected  0 warnings
                   // --------------------
                   // Total    47 warnings

    return 0;
}
