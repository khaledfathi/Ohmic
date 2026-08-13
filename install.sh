#!/bin/bash
g++ -std=c++17 -Os -flto -s -fdata-sections -ffunction-sections -Wl,--gc-sections ./src/*.cpp main.cpp -o ./build/bin/ohmic
sudo cp ./build/bin/ohmic /usr/local/bin/ohmic
sudo chmod +x /usr/local/bin/ohmic
