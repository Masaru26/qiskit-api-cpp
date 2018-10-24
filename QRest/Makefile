# Copyright by Benjamin Luxbacher

CXX = g++
CXXFLAGS = -c -Wall -std=c++11 -fpic
LIBINCLUDEFLAGS = -lcurl -ljsoncpp
LIBPATH = /usr/lib

EXCEPTIONOBJECTS = Exceptions/WebRequestException.o
QJOBEXECUTION = QJobExecution/QQueueResult.o QJobExecution/QExecution.o QJobExecution/QInfoQueue.o
QAVAILABLEBACKENDS = QAvailableBackends/QBackend.o
OBJECTS = $(EXCEPTIONOBJECTS) $(QJOBEXECUTION) $(QAVAILABLEBACKENDS) RestConnection.o



all: libqiskit.so

libqiskit.so: $(OBJECTS)
	$(CXX) $(OBJECTS) $(LIBINCLUDEFLAGS) -shared -o libqiskit.so



RestConnection.o: RestConnection.cpp RestConnection.h
	$(CXX) RestConnection.cpp -o RestConnection.o $(CXXFLAGS)
	

QBackend.o: QAvailableBackends/QBackend.cpp QAvailableBackends/QBackend.h
	$(CXX) QBackend.cpp -o QBackend.o $(CXXFLAGS)


QQueueResult.o: QJobExecution/QQueueResult.cpp QJobExecution/QQueueResult.h
	$(CXX) QQueueResult.cpp -o QQueueResult.o $(CXXFLAGS)

QExecution.o: QJobExecution/QExecution.cpp QJobExecution/QExecution.h
	$(CXX) QExecution.cpp -o QExecution.o $(CXXFLAGS)

QInfoQueue.o: QJobExecution/QInfoQueue.cpp QJobExecution/QInfoQueue.h
	$(CXX) QInfoQueue.cpp -o QInfoQueue.o $(CXXFLAGS)



WebRequestException.o: Exceptions/WebRequestException.cpp Exceptions/WebRequestException.h
	$(CXX) Exceptions/WebRequestException.cpp -o Exceptions/WebRequestException.o $(CXXFLAGS)



install:
	install ./libqiskit.so $(LIBPATH)

uninstall:
	rm -f $(LIBPATH)/libqiskit.so

clean:
	rm -f *.o
	rm -f Exceptions/*.o

clear: clean
	rm -f libqiskit.so