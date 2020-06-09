# I use the -w tag to inhibit a warning against deleting a void pointer, but it seems to work alright.
def:
	@g++ -c -w -std=c++14 chain.cpp 
	@g++ -o chain chain.o