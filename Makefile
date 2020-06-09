# I use the -w tag to inhibit a warning against deleting a void pointer, but it seems to work alright.
chainDriver:  chain.o chainDriver.o chain.h
	g++ -w -std=c++14 -o chainDriver chain.o chainDriver.o 

chain.o: chain.cpp chain.h
	g++ -w -std=c++14 -c chain.cpp

chainDriver.o: chainDriver.cpp chain.h
	g++ -w -std=c++14 -c chainDriver.cpp

clean:
	rm *.o chain