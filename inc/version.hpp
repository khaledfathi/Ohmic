/**
 * @file version.hpp
 * @brief define the app info strings
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#ifndef VERSION_HPP
#define VERSION_HPP

#include <string_view>

namespace AppInfo {

constexpr std::string_view VERSION =
    "Ohmic version :\t2.0.0\nLicense :\tGPLv3\nAuthor :\tKhaled Fathi "
    "<dev@khaledfathi.com>\nSource "
    ":\thttps://github.com/khaledfathi/Ohmic";
// constexpr std::string_view NAME = "ohmic";
// constexpr std::string_view VERSION = "2.0.0";
// constexpr std::string_view AUTHOR = "Khaled Fathi <dev@khaledfathi.com>";
// constexpr std::string_view DESCRIPTION = "Simple CLI Ohm's law calculator";
// constexpr std::string_view LICENSE = "GPLv3";
// constexpr std::string_view GITHUB = "https://github.com/khaledfathi/Ohmic";
} // namespace AppInfo

#endif // VERSION_HPP
