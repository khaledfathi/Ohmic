# Ohmic Cli Ohm calculator 

![Version](https://img.shields.io/badge/version-v2.1.0-blue) ![C++17](https://img.shields.io/badge/C%2B%2B-17-00599C?logo=c%2B%2B) ![GitHub License](https://img.shields.io/github/license/khaledfathi/ohmic)


A lightweight CLI tool built in C++17.
Ohm law calculor ( Voltage , Current , Resistance , Power ).

##  What's New in v2.1.0

- add -H option for human readable 
- limit decimal points to 3 

### Usage : 

``` shell
$ ohmic --help
Ohmic [ohm calculator (Voltage , Current , Resistance , Power)]


ohmic [OPTIONS]


OPTIONS:
  -h,     --help              Print this help message and exit
  -H,     --human             human readable (i.e 1244 Volts , 1.244K Volts )
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
$ ohmic  -H -V 16000 -I 250
Voltage :	16.000 Kilo Volts
Current :	250.000 Amps
Resistance :	64.000 Ohms
Power :		4.000 Mega Watts
```

### Compile (Linux) 
```shell
g++ -std=c++17 -Os -flto -s -fdata-sections -ffunction-sections -Wl,--gc-sections ./src/*.cpp main.cpp -o ./build/bin/ohmic
sudo cp ./build/bin/ohmic /usr/local/bin/ohmic
sudo chmod +x /usr/local/bin/ohmic
```
or download the **[bin file](https://github.com/khaledfathi/Ohmic/raw/refs/heads/main/build/bin/ohmic)**