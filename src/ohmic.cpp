/**
 * @file ohmic.cpp
 * @brief implementation of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.1
 *
 * @copyright this project is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/ohmic.hpp"
#include "../inc/calculator.hpp"
#include "../inc/version.hpp"
#include <cstdlib>
#include <cmath>
#include <string>
#include <string_view>
#include <format>
#include <print>
//
namespace ohmic
{

  void setCliOptions(CLI::App &app, ohmic::options &options, char **argv)
  {
    argv = app.ensure_utf8(argv);
    // general options
    app.add_flag("-H,--human", options.human, "human readable (i.e 1244 Volts , 1.244K Volts )");
    app.set_version_flag("-v,--version",static_cast<std::string>(ohmic::info::VERSION), "version of the app ");
    // Create an Option Group for the electrical parameters
    auto *calc_group = app.add_option_group( "Electrical Parameters", "Provide exactly two values to calculate the remaining two");
    //
    calc_group->add_option("-V,--voltage", options.voltage, "voltage value");
    calc_group->add_option("-I,--current", options.current, "current value in Amps ");
    calc_group->add_option("-R,--resistance", options.resistance, "resistance value in Ohms");
    calc_group->add_option("-P,--power", options.power, "power value in Watts");
    // exact two options required for calcualtoin
    calc_group->require_option(2);
  }

  std::string humanReadable(double value, std::string_view unit, int decimal)
  {
    if (value >= 1e9)
      return std::format("{} Giga {}", formatDouble(value / 1e9, decimal), unit);
    if (value >= 1e6)
      return std::format("{} Mega {}", formatDouble(value / 1e6, decimal), unit);
    if (value >= 1e3)
      return std::format("{} Kilo {}", formatDouble(value / 1e3, decimal), unit);
    if (value >= 1.0)
      return std::format("{} {}", formatDouble(value, decimal), unit);
    if (value >= 1e-3)
      return std::format("{} mili {}", formatDouble(value * 1e3, decimal), unit);
    if (value >= 1e-6)
      return std::format("{} micro {}", formatDouble(value * 1e6, decimal), unit);
    if (value >= 1e-9)
      return std::format("{} nano {}", formatDouble(value * 1e9, decimal), unit);

    return std::format("{} {}", formatDouble(value, decimal), unit);
  }

  std::string formatDouble(const double val, int decimal)
  {
    return std::format("{:.{}f}", val, decimal);
  }
  double limitToDecimals(double value, int decimals)
  {
    double factor = std::pow(10.0, decimals);
    return std::round(value * factor) / factor;
  }

  void print_results(ohmic::Calculator::ohmValues &ohm_values, bool isHumanReadable = false)
  {
    if (isHumanReadable)
    {
      std::println("Voltage :    {} " ,humanReadable(ohm_values.v, "Volts") );
      std::println("Current :    {} " ,humanReadable(ohm_values.i, "Amps") );
      std::println("Resistance : {} " ,humanReadable(ohm_values.r, "Ohms") );
      std::println("Power:       {}" ,humanReadable(ohm_values.p, "Watts") );
    }
    else
    {
      std::println("Voltage :    {:.2f} Volts" ,ohm_values.v );
      std::println("Current :    {:.2f} Amps " ,ohm_values.i );
      std::println("Resistance : {:.2f} Ohms " ,ohm_values.r );
      std::println("Power:       {:.2f} Watts " ,ohm_values.p );
    }
  }
  int run(const ohmic::options &options)
  {

    double v = options.voltage.value_or(-1);
    double i = options.current.value_or(-1);
    double r = options.resistance.value_or(-1);
    double p = options.power.value_or(-1);

    ohmic::Calculator calc{v, i, r, p};
    ohmic::Calculator::ohmValues results = calc.results();

    print_results(results, options.human);

    return EXIT_SUCCESS;
  }

} // namespace ohmic
