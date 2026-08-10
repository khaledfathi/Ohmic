# Ohmic Cli Ohm calculator 

![Version](https://img.shields.io/badge/version-v1.0.0-blue) ![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B) ![GitHub License](https://img.shields.io/github/license/khaledfathi/ohmic)


A lightweight CLI tool built in C++17.
Ohm law calculor ( Voltage , Current , Resistance , Power ).

### Usage : 

``` shell
$ ohmic  --help
Usage: ohmic <option> <value1> <option> <value2>
Options:
  -v, --volt <val>         Voltage (Volts)
  -i, --current <val>      Current (Amps)
  -r, --resistance <val>   Resistance (Ohms)
  -p, --power <val>        Power (Watts)
  -h, --help               Show this help menu
  -V, --version            Show version
Example : 
  ohm --volt 220 --power 500

```

### Example 

``` shell
$ ohmic  -p 2500 -v 220
Voltage : 220
Current : 11.3636
Resistance : 19.36
Power : 2500

```

### Compile (Linux) 
```shell
g++ -std=c++17 -Os -flto -s -fdata-sections -ffunction-sections -Wl,--gc-sections ./src/*.cpp main.cpp -o ./build/bin/ohmic
sudo cp ./build/bin/ohmic /usr/local/bin/ohmic
sudo chmod +x /usr/local/bin/ohmic
```
or download the **[bin file](https://github.com/khaledfathi/Ohmic/raw/refs/heads/main/build/bin/ohmic)**