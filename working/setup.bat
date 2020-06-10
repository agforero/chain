@echo off
REM -h tag as not to freak out the user
g++ -c -w -std=c++14 chain.cpp
g++ -o chain chain.o