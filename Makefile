# I use the -w tag to inhibit a warning against deleting a void pointer, but it seems to work alright.
def: 
	@g++ -w -std=c++14 -c chainDriver.cpp chain.h
	@g++ -w -std=c++14 -o chainDriver chainDriver.o 
	@del chain.h.gch
	# I have no idea what this file is, but it seems to create itself whenever I compile.

clean:
	@rm *.o chain