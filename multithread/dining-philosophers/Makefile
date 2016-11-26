
CXX=g++
CXXFLAGS=-g -std=c++11 -pthread #-Wall

all : main

main : main.o
	$(CXX) -o main main.o $(CXXFLAGS)

main.o : main.cpp
	$(CXX) -c main.cpp $(CXXFLAGS)

clean :
	rm -f *.o main
