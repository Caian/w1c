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

#pragma once

namespace w1c {

/**
 * Convert value from a type to another.
 *
 * @tparam TTo The type of the result.
 * @tparam TFrom The type of the source.
 *
 * @param to A reference to the result of the assignment
 * @param from A constant reference to assign to the result.
 *
 * @note This method will perform simple assignments by default, 
 * so it will trigger compilation warnings if the source value 
 * does not fit into the result. To disable cast warnings and
 * change the behavior to a static_cast, one can define
 * W1C_SILENT_CAST before including to.hpp.
 */
template <typename TTo, typename TFrom>
inline static void to(TTo& to, const TFrom& from)
{
#if !defined(W1C_SILENT_CAST)
    to = from;
#else
    to = static_cast<TTo>(from);
#endif
}

/**
 * Convert value from a type to another.
 *
 * @tparam TTo The type of the result.
 * @tparam TFrom The type of the source.
 *
 * @param from A constant reference to assign to the result.
 *
 * @return The source value converted to the return type.
 *
 * @note This method will perform a simple return by default,
 * so it will trigger compilation warnings if the source value
 * does not fit into the result. To disable cast warnings and
 * change the behavior to a static_cast, one can define
 * W1C_SILENT_CAST before including to.hpp.
 */
template <typename TTo, typename TFrom>
inline static TTo to(const TFrom& from)
{
#if !defined(W1C_SILENT_CAST)
    return from;
#else
    return static_cast<TTo>(from);
#endif
}

}
