/**
 * @file ohmic.hpp
 * @brief header of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include <optional>
#ifndef OHMIC_HPP

#include "../inc/ext/CLI11.hpp"

namespace ohmic
{

  /**
   * @brief cli options structure
   *
   */
  struct options
  {
    std::optional<double> voltage;
    std::optional<double> current;
    std::optional<double> resistance;
    std::optional<double> power;
    std::optional<int> decimal_points{3};
    std::optional<bool> version = false;
  };

  /**
   * @brief Set the Cli Options object ( required CLI11 )
   *
   * @param app CLI11 app object
   * @param options cli option structure
   * @param argv cli arguments array
   */
  void setCliOptions(CLI::App &app, ohmic::options &options, char **argv);

  /**
   * @brief application start point
   *
   * @param app CLI11 app object
   * @return exit status
   */
  int run(const ohmic::options &options);
} // namespace ohmic

#endif // !OHMIC_HPP
