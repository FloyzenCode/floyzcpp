#!/bin/bash

echo "Установка зависимостей... "

git clone https://github.com/FloyzenCode/floyzcpp
cd floyzcpp/src
g++ -std=c++17 -o floyzcpp main.cpp

if [ $? -eq 0 ]; then
    echo "Установка завершена!"
else
    echo "Произошла ошибка при установке."
fi
