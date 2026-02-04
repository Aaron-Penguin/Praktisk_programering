CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Out.txt : main             # Creating an txt file for the output
	./main > Out.txt

main: main.o source.o
	$(CXX) main.o source.o -o main

main.o: main.cc header.h
	$(CXX) $(CXXFLAGS) -c main.cc

source.o: source.cc header.h
	$(CXX) $(CXXFLAGS) -c source.cc

clean:
	rm -f main.o Out.txt source.o