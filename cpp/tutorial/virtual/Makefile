
CXX=g++
CXXFLAGS=-g -std=c++11 #-Wall

all : main

main : main.o Person.o Professor.o Student.o
	$(CXX) -o main main.o Person.o Professor.o Student.o

main.o : main.cpp
	$(CXX) $(CXXFLAGS) -c main.cpp

Person.o : Person.cpp
	$(CXX) $(CXXFLAGS) -c Person.cpp

Professor.o : Professor.cpp
	$(CXX) $(CXXFLAGS) -c Professor.cpp

Student.o : Student.cpp
	$(CXX) $(CXXFLAGS) -c Student.cpp

clean :
	rm -f *.o main
