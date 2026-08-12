# Ohmic Cli Ohm calculator 

![Version](https://img.shields.io/badge/version-v2.0.0-blue) ![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B) ![GitHub License](https://img.shields.io/github/license/khaledfathi/ohmic)


A lightweight CLI tool built in C++17.
Ohm law calculor ( Voltage , Current , Resistance , Power ).

##  What's New in v2.0.0

rebuild cli parser with CLI11 lib . 
change options flags .

### Usage : 

``` shell
$ ohmic --help 
Ohmic [ohm calculator (Voltage , Current , Resistance , Power)]


ohmic [OPTIONS]


OPTIONS:
  -h,     --help              Print this help message and exit
  -v,     --version           version of the app
[Option Group: Electrical Parameters]
  Provide exactly two values to calculate the remaining two
  [Exactly 2 of the following options are required]
  

  OPTIONS:
    -V,     --voltage FLOAT     voltage value
    -I,     --current FLOAT     current value in Amps
    -R,     --resistance FLOAT  resistance value in Ohms
    -P,     --power FLOAT       power value in Watts
```

### Example 

``` shell
$ ohmic -V 220 -P 5400
Voltage :	220 Volts
Current :	24.5455 Amps
Resistance :	8.96296 Ohms
Power :		5400 Watts

```

### Compile (Linux) 
```shell
g++ -std=c++17 -Os -flto -s -fdata-sections -ffunction-sections -Wl,--gc-sections ./src/*.cpp main.cpp -o ./build/bin/ohmic
sudo cp ./build/bin/ohmic /usr/local/bin/ohmic
sudo chmod +x /usr/local/bin/ohmic
```
or download the **[bin file](https://github.com/khaledfathi/Ohmic/raw/refs/heads/main/build/bin/ohmic)**