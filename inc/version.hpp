/**
 * @file version.hpp
 * @brief define the app info strings
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.1
 *
 * @copyright this project is open source
 * Licensed under the GPLv3 License.
 */

#ifndef VERSION_HPP
#define VERSION_HPP

#include <string_view>

namespace ohmic::info
{
    constexpr std::string_view DESCRIPTION = "Ohmic [ohm calculator (Voltage , Current , Resistance , Power)]";
    constexpr std::string_view VERSION =
        "Ohmic version :\t2.1.1\nLicense :\tGPLv3\nAuthor :\tKhaled Fathi "
        "<dev@khaledfathi.com>\nSource "
        ":\thttps://github.com/khaledfathi/Ohmic";
} // namespace ohmic::info

#endif // VERSION_HPP
