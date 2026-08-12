/**
 * @file types.hpp
 * @brief header of types used in (Ohm Calculator App [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */
#ifndef TYPES_HPP
#define TYPES_HPP

#include <optional>

namespace app
{

  /**
   * @brief  structure for CLI parser
   *
   */
  struct Args
  {
    std::optional<double> v; // Voltage
    std::optional<double> i; // Current (Amps)
    std::optional<double> r; // Resistance (Ohms)
    std::optional<double> p; // Power (Watts)
  };

} // namespace app

#endif // !TYPES_HPP
