/**
 * @file ohmic.cpp
 * @brief implementation of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/ohmic.hpp"
#include "../inc/calculator.hpp"
#include "../inc/version.hpp"
#include <cstdlib>
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

  std::string humanReadable(double value, std::string unit, int decimal)
  {
    std::string res;
    if (value >= 1e9)
    { // over mega
      res = formatDouble(value / 1e9, decimal) + " Giga " + unit;
    }
    else if (value >= 1e6 && value < 1e9)
    {
      res = formatDouble(value / 1e6, decimal) + " Mega " + unit;
    }
    else if (value >= 1e3 && value < 1e6)
    {
      res = formatDouble(value / 1e3, decimal) + " Kilo " + unit;
    }
    else if (value >= 1e-3 && value < 1.0)
    {
      res = formatDouble(value * 1e3, decimal) + " mili " + unit;
    }
    else if (value >= 1e-6 && value < 1e-3)
    {
      res = formatDouble(value * 1e6, decimal) + " micro  " + unit;
    }
    else if (value >= 1e-9 && value < 1e-6)
    {
      res = formatDouble(value * 1e9, decimal) + " nano " + unit;
    }
    else
    {
      res = formatDouble(value, decimal) + " " + unit;
    }
    return res;
  }

  std::string formatDouble(const double val, int decimal)
  {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(decimal) << val;
    return stream.str();
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
      std::print("Voltage :\t {} \n" ,humanReadable(ohm_values.v, "Volts") );
      std::print("Current :\t {} \n" ,humanReadable(ohm_values.i, "Amps") );
      std::print("Resistance : \t {} \n" ,humanReadable(ohm_values.r, "Ohms") );
      std::print("Power:\t\t {} \n" ,humanReadable(ohm_values.p, "Watts") );
    }
    else
    {
      std::print("Voltage :\t {} Volts\n" ,limitToDecimals(ohm_values.v) );
      std::print("Current :\t Amps{} \n" ,limitToDecimals(ohm_values.i) );
      std::print("Resistance : \t Ohms{} \n" ,limitToDecimals(ohm_values.r) );
      std::print("Power:\t\t Watts{} \n" ,limitToDecimals(ohm_values.p) );
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
