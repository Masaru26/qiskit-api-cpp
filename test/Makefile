LIBDIR := $(shell dirname $(realpath ../IBMQuantumExperience/$(lastword $(MAKEFILE_LIST))))

all: test

test: main.cpp
	g++ -L$(LIBDIR) -Wall -o test main.cpp -lqiskit

clear:
	rm -f test