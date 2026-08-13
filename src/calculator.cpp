/**
 * @file ohm_calc.cpp
 * @brief implementation of OhmCalc
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/calculator.hpp"
#include <cmath>
#include <iostream>

namespace ohmic
{

  Calculator::Calculator(double v, double i, double r, double p)
  {
    values.v = v;
    values.i = i;
    values.r = r;
    values.p = p;
    calculate();
  }

  void Calculator::calculate()
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

  double Calculator::voltage_i_r() { return values.r * values.i; }
  double Calculator::voltage_i_p() { return values.p / values.i; }
  double Calculator::voltage_r_p() { return std::sqrt(values.p * values.r); }

  double Calculator::current_v_r() { return values.v / values.r; }
  double Calculator::current_v_p() { return values.p / values.v; }
  double Calculator::current_r_p() { return std::sqrt(values.p / values.r); }

  double Calculator::resistance_v_i() { return values.v / values.i; }
  double Calculator::resistance_v_p() { return std::pow(values.v, 2) / values.p; }
  double Calculator::resistance_i_p() { return values.p / std::pow(values.i, 2); }

  double Calculator::power_v_r() { return std::pow(values.v, 2) / values.r; }
  double Calculator::power_v_i() { return values.v * values.i; }
  double Calculator::power_i_r() { return values.r * std::pow(values.i, 2); }

  Calculator::ohmValues Calculator::results() const { return values; }

} // namespace ohmic
