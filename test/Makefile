LIBDIR := $(shell dirname $(realpath ../IBMQuantumExperience/$(lastword $(MAKEFILE_LIST))))

CXX = g++
CXXFLAGS = -Wall -std=c++11

all: test

test: main.cpp
	$(CXX) main.cpp -L$(LIBDIR) -lqiskit -o test $(CXXFLAGS)

clear:
	rm -f test