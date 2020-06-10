@echo off
REM I use the -w tag to inhibit a warning against deleting a void pointer, but it seems to work alright.
REM g++ -w -std=c++14 -c chain.cpp chain.h
g++ -w -std=c++14 -c chainDriver.cpp chain.h
g++ -w -std=c++14 -o chainDriver chainDriver.o 
del chain.h.gch