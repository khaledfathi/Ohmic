/**
 * @file ohm_calc.cpp
 * @brief implementation of OhmCalc
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/ohm_calc.hpp"
#include <iostream>
#include <cmath>

namespace app
{

  void OhmCalc::calculate()
  {
    if (values.v > -1 && values.i > -1)
    {
      values.r = resistance_v_i();
      values.p = power_v_r();
    }
    else if (values.v > -1 && values.r > -1)
    {
      values.i = current_v_r();
      values.p = power_v_r();
    }
    else if (values.v > -1 && values.p > -1)
    {
      values.i = current_v_p();
      values.r = resistance_v_p();
    }
    else if (values.i > -1 && values.r > -1)
    {
      values.v = voltage_i_r();
      values.p = power_i_r();
    }
    else if (values.i > -1 && values.p > -1)
    {
      values.v = voltage_i_p();
      values.r = resistance_i_p();
    }
    else if (values.r > -1 && values.p > -1)
    {
      values.v = voltage_r_p();
      values.i = current_r_p();
    }
  }

  double OhmCalc::voltage_i_r() { return values.r * values.i; }
  double OhmCalc::voltage_i_p() { return values.p / values.i; }
  double OhmCalc::voltage_r_p() { return std::sqrt(values.p * values.r); }

  double OhmCalc::current_v_r() { return values.v / values.r; }
  double OhmCalc::current_v_p() { return values.p / values.v; }
  double OhmCalc::current_r_p() { return std::sqrt(values.p / values.r); }

  double OhmCalc::resistance_v_i() { return values.v / values.i; }
  double OhmCalc::resistance_v_p() { return std::pow(values.v, 2) / values.p; }
  double OhmCalc::resistance_i_p() { return values.p / std::pow(values.i, 2); }

  double OhmCalc::power_v_r() { return std::pow(values.v, 2) / values.r; }
  double OhmCalc::power_v_i() { return values.v * values.i; }
  double OhmCalc::power_i_r() { return values.r * std::pow(values.i, 2); }

  OhmCalc::OhmCalc(double v, double i, double r, double p)
  {
    values.v = std::round(v * 100) / 100;
    values.i = std::round(i * 100) / 100;
    values.r = std::round(r * 100) / 100;
    values.p = std::round(p * 100) / 100;
    calculate();
  }
  OhmCalc::ohmValues OhmCalc::results() const { return values; }

  void OhmCalc::print_result() const
  {
    std::cout << "Voltage : " << values.v << std::endl;
    std::cout << "Current : " << values.i << std::endl;
    std::cout << "Resistance : " << values.r << std::endl;
    std::cout << "Power : " << values.p << std::endl;
  }

} // namespace app
