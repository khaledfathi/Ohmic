/**
 * @file ohmic.cpp
 * @brief implementation of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/ohmic.hpp"
#include "../inc/calculator.hpp"
#include "../inc/version.hpp"
#include <cstdlib>
#include <iostream>

namespace ohmic
{
  void setCliOptions(CLI::App &app, ohmic::options &options, char **argv)
  {
    argv = app.ensure_utf8(argv);
    // general options
    app.add_option("-d,--decimals", options.decimal_points, "Number of decimal places in output - default=3 ");
    app.set_version_flag("-v,--version", (std::string)ohmic::info::VERSION, "version of the app ");
    // Create an Option Group for the electrical parameters
    auto *calc_group = app.add_option_group("Electrical Parameters", "Provide exactly two values to calculate the remaining two");
    //
    calc_group->add_option("-V,--voltage", options.voltage, "voltage value");
    calc_group->add_option("-I,--current", options.current, "current value in Amps ");
    calc_group->add_option("-R,--resistance", options.resistance, "resistance value in Ohms");
    calc_group->add_option("-P,--power", options.voltage, "power value in Watts");
    // exact two options required for calcualtoin
    calc_group->require_option(2);
  }

  int run(const ohmic::options &options)
  {

    double v = options.voltage.value_or(-1);
    double i = options.current.value_or(-1);
    double r = options.resistance.value_or(-1);
    double p = options.power.value_or(-1);
    ohmic::Calculator calc{v, i, r, p};

    ohmic::Calculator::ohmValues results = calc.results();
    std::cout << "Voltage :\t" << results.v << " Volts" << std::endl;
    std::cout << "Current :\t" << results.i << " Amps" << std::endl;
    std::cout << "Resistance :\t" << results.r << " Ohms" << std::endl;
    std::cout << "Power :\t" << results.p << " Watts" << std::endl;
    return EXIT_SUCCESS;
  }

} // namespace ohmic
