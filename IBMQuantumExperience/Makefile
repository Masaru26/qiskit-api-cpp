CXX = g++
CXXFLAGS = -c -Wall -std=c++11 -fpic

EXCEPTIONOBJECTS = Exceptions/ApiException.o Exceptions/BadBackendException.o \
Exceptions/CredentialsException.o Exceptions/RegisterSizeException.o

OBJECTS = $(EXCEPTIONOBJECTS) IBMQuantumExperience.o Credentials.o Request.o



all: libqiskit.so

libqiskit.so: $(OBJECTS)
	$(CXX) $(OBJECTS) -lcurl -shared -o libqiskit.so

IBMQuantumExperience.o: IBMQuantumExperience.cpp IBMQuantumExperience.h
	$(CXX) IBMQuantumExperience.cpp -o IBMQuantumExperience.o $(CXXFLAGS)

Credentials.o: Credentials.cpp Credentials.h
	$(CXX) Credentials.cpp -o Credentials.o $(CXXFLAGS)

Request.o: Request.cpp Request.h
	$(CXX) Request.cpp -o Request.o $(CXXFLAGS)



ApiException.o: Exceptions/ApiException.cpp Exceptions/ApiException.h
	$(CXX) Exceptions/ApiException.cpp -o Exceptions/ApiException.o $(CXXFLAGS)

BadBackendException.o: Exceptions/BadBackendException.cpp Exceptions/BadBackendException.h
	$(CXX) Exceptions/BadBackendException.cpp -o Exceptions/BadBackendException.o $(CXXFLAGS)

CredentialsException.o: Exceptions/CredentialsException.cpp Exceptions/CredentialsException.h
	$(CXX) Exceptions/CredentialsException.cpp -o Exceptions/CredentialsException.o $(CXXFLAGS)

RegisterSizeException.o: Exceptions/RegisterSizeException.cpp Exceptions/RegisterSizeException.h
	$(CXX) Exceptions/RegisterSizeException.cpp -o Exceptions/RegisterSizeException.o $(CXXFLAGS)



clean:
	rm -f *.o
	rm -f Exceptions/*.o

clear: clean
	rm -f libqiskit.so