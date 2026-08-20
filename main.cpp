/**
 * @file main.cpp
 * @brief Ohmic is a Simple CLI tool for calculating Ohm's Law
 * (Voltage, Current,Resistance, Power).
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.1
 *
 * @copyright this project is open source
 * Licensed under the GPLv3 License.
 */

#include "./inc/ext/CLI11.hpp"
#include "./inc/ohmic.hpp"
#include "./inc/version.hpp"

int main(int argc, char **argv) {
  // cli parser
  CLI::App app{std::string{ohmic::info::DESCRIPTION}};
  ohmic::options options;

  ohmic::setCliOptions(app, options, argv);
  CLI11_PARSE(app, argc, argv);
  //
  // Run app logic
  return ohmic::run(options);
}
