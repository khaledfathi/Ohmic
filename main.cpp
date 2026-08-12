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
#include "./inc/version.hpp"

int main(int argc, char **argv) {
  CLI::App app{
      "Ohmic [ohm calculator (Voltage , Current , Resistance , Power)]"};
  argv = app.ensure_utf8(argv);

  struct options {
    double voltage{0.0};
    double current{0.0};
    double resistance{0.0};
    double power{0.0};
    int decimal_points{3};
    std::string_view history_file;
    bool human_readable_flag = false;
    bool version = false;
  } options;

  // general options
  app.add_option("-d,--decimals", options.decimal_points,
                 "Number of decimal places in output - default=3 ");
  app.add_option("-f,--file", options.history_file,
                 "history file to store results");
  app.add_flag("-H", options.human_readable_flag,
               "human readable values [1200 => 1.2K]");
  app.set_version_flag("-v,--version",(std::string)AppInfo::VERSION, "version of the app ");
  // Create an Option Group for the electrical parameters
  auto *calc_group = app.add_option_group(
      "Electrical Parameters",
      "Provide exactly two values to calculate the remaining two");
  //
  calc_group->add_option("-V,--voltage", options.voltage, "voltage value");
  calc_group->add_option("-I,--current", options.current,
                         "current value in Amps ");
  calc_group->add_option("-R,--resistance", options.resistance,
                         "resistance value in Ohms");
  calc_group->add_option("-P,--power", options.voltage, "power value in Watts");
  // exact two options required for calcualtoin
  calc_group->require_option(2);

  CLI11_PARSE(app, argc, argv);
  return 0;
}
