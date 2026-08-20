#!/bin/bash
g++ -std=c++23 -Os -flto -s -fdata-sections -ffunction-sections -Wl,--gc-sections ./src/*.cpp main.cpp -o ./build/ohmic
sudo cp ./build/ohmic /usr/local/bin/ohmic
sudo chmod +x /usr/local/bin/ohmic
