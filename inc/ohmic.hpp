/**
 * @file ohmic.hpp
 * @brief header of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.1
 *
 * @copyright this project is open source
 * Licensed under the GPLv3 License.
 */

#include <optional>
#include <string_view>
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
    std::optional<int> decimal_points{3}; // decimal points for results values
    bool human = false;                   // human readable flag
    bool version = false;
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
   * @brief convert double value to human readable (i.e 10000000A = 10MA, 0.005A = 5mA 5000V = 5KV , 0.0000300 = 300uV ... etc )
   *
   * @param value [in] refrence to the value to use for calculate
   * @param unit [in] [Volts, Amps , Ohms , Watts]
   * @param decimal [in] limits  results  decimal (i.e 1.23455  => limits 2 point =  1.235)
   * @return string of human readable format
   */
  std::string humanReadable(double value, std::string_view unit, int decimal = 3);

  // 
  /**
   * @brief Helper to convert double to string with exact decimal precision
   * 
   * @param val double value to be formated 
   * @param decimal  decimal limits 
   * @return formated string  of the double value 
   */
  std::string formatDouble(const double val, int decimal = 3);

  /**
   * @brief limits decimals of a double value
   *
   * @param value [in,out] refrenece value to change
   * @param decimals [in]  how many decimal points allowed
   * @return refrence to the value
   *
   */
  double limitToDecimals(double value, int decimals = 3);

  /**
   * @brief application start point
   *
   * @param app CLI11 app object
   * @return exit status
   */
  int run(const ohmic::options &options);
} // namespace ohmic

#endif // !OHMIC_HPP
