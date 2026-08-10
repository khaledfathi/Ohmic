/**
 * @file app.cpp
 * @brief implementation of core functions of (ohm calculator app [ohmic])
 * @author Khaled Fathi <dev@khaledfathi.com>
 * @date 2026-08-10
 * @version 1.0.0
 *
 * @copyright this porject is open source
 * Licensed under the GPLv3 License.
 */

#include "../inc/app.hpp"
#include "../inc/version.hpp"
#include <cmath>
#include <iostream>
#include <stdexcept>
#include <map>

namespace app
{

  void print_help()
  {
    std::cout << "Usage: ohmic <option> <value1> <option> <value2>\n"
              << "Options:\n"
              << "  -v, --volt <val>      Voltage (Volts)\n"
              << "  -i, --current <val>      Current (Amps)\n"
              << "  -r, --resistance <val>      Resistance (Ohms)\n"
              << "  -p, --power <val>      Power (Watts)\n"
              << "  -h, --help    Show this help menu\n"
              << "  -V, --version Show version\n"
              << "Example : \n"
              << "  ohm --volt 220 --power 500\n";
  }

  bool parseCLI(int argc, char *argv[], Args &args)
  {
    // argc should has at least 1 option
    if (argc < 2)
    {
      print_help();
      return false;
    }
    //
    std::map<std::string_view, int> optionsMonitor = {{"-v", 0}, {"-i", 0}, {"-r", 0}, {"-p", 0}};
    try
    {
      for (int i = 1; i < argc; ++i)
      {
        std::string_view arg = argv[i];
        if (arg == "-h" || arg == "--help")
        {
          args.help = true;
        }
        else if (arg == "-V" || arg == "--version")
        {
          args.version = true;
        }
        else if (arg == "-v" || arg == "--volt" && i + 1 < argc)
        {
          args.v = std::abs(std::stod(argv[++i]));
          optionsMonitor[arg]++;
        }
        else if (arg == "-i" || arg == "--current" && i + 1 < argc)
        {
          args.i = std::abs(std::stod(argv[++i]));
          optionsMonitor[arg]++;
        }
        else if (arg == "-r" || arg == "--resistance" && i + 1 < argc)
        {
          args.r = std::abs(std::stod(argv[++i]));
          optionsMonitor[arg]++;
        }
        else if (arg == "-p" || arg == "--power" && i + 1 < argc)
        {
          args.p = std::abs(std::stod(argv[++i]));
          optionsMonitor[arg]++;
        }
        else
        {
          print_help();
          return false;
        }
      }
    }
    catch (std::out_of_range e)
    {
      std::cout << "Error : value/s is out of range !" << std::endl;
      return false;
    }
    catch (std::invalid_argument e)
    {
      std::cout << "Error : value/s is not a number !" << std::endl;
      return false;
    }
    catch (std::logic_error e)
    {
      std::cout << "Error : missing value/s !" << std::endl;
      return false;
    }

    if (args.version && argc == 2)
    {
      std::cout << "Version : " << AppInfo::VERSION << std::endl;
      std::cout << "Description : " << AppInfo::DESCRIPTION << std::endl;
      std::cout << "Source code : " << AppInfo::GITHUB<< std::endl;
      std::cout << "License : " << AppInfo::LICENSE<< std::endl;
      return false;
    }
    // ensure two values is inserted (i.e 'ohm -v 220 -r 10' )
    if (argc != 5)
    {
      print_help();
      return false;
    }
    // check duplicated options
    for (auto option : optionsMonitor)
    {
      if (option.second > 1)
      {
        std::cout << "option " << option.first << " is duplicated ! " << std::endl;
        return false;
      }
    }
    return true;
  }

} // namespace app
