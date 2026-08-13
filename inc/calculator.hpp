/**
 * @file calculator.hpp
 * @brief header of calculator , Calculate values depends on  "Ohm Law
 * Equations"
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 2.1.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */
#ifndef OHM_CALC_HPP
#define OHM_CALC_HPP

namespace ohmic
{

  /**
   * @brief Ohm law calculator
   *
   */
  class Calculator
  {
  public:
    /**
     * @brief  Structure for ohm values
     *
     */
    struct ohmValues
    {
      double v;
      double i;
      double r;
      double p;
    };
    /**
     * @brief Construct a new Ohm Calc object
     *
     * @param v voltage in volt
     * @param i current in amps
     * @param r resistance in ohm
     * @param p power in watt
     */
    Calculator(double v, double i, double r, double p);

    /**
     * @brief return object of calculated ohm values
     *
     * @return ohmValues object
     */
    ohmValues results() const;

  private:
    ohmValues values;

    void calculate();

    // calculate voltage methods
    double voltage_i_r();
    double voltage_i_p();
    double voltage_r_p();

    // calculate current methods
    double current_v_r();
    double current_v_p();
    double current_r_p();

    // calculate resistance methods
    double resistance_v_i();
    double resistance_v_p();
    double resistance_i_p();

    // calculate power  methods
    double power_v_i();
    double power_v_r();
    double power_i_r();
  };

} // namespace ohmic

#endif
