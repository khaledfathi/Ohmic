/**
 * @file main.cpp
 * @brief Ohmic is a Simple CLI tool for calculating Ohm's Law
 * (Voltage, Current,Resistance, Power).
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "./inc/ext/CLI11.hpp"
#include "./inc/ohmic.hpp"
#include "./inc/version.hpp"

int main(int argc, char **argv) {
  // cli parser
  CLI::App app{(std::string)ohmic::info::DESCRIPTION};
  ohmic::options options;
  ohmic::setCliOptions(app, options, argv);
  CLI11_PARSE(app, argc, argv);
  // run app
  return ohmic::run(options);
}
