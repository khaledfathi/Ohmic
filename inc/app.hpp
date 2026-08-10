/**
 * @file app.hpp
 * @brief header of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#ifndef APP_HPP

#include "./types.hpp"

namespace app
{

    /**
     * @brief print command -h --help text
     *
     * @return * void
     */
    void print_help();
    /**
     * @brief handle the CLI argument and build the option status on [args]
     *
     * @param argc[in]  arguments count
     * @param argv[in]  arguments array
     * @param args[in,out]  fixed refrenece for [args] that hold the option results
     * @return true for success , false for fail
     */
    bool parseCLI(int argc, char *argv[], Args &args);

} // namespace app

#endif // !APP_HPP
