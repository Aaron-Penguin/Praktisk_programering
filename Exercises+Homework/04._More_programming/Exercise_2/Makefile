CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Out.txt : main             # Creating an txt file for the output
	./main > Out.txt

main: main.o
	$(CXX) main.o -o main

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

clean:
	rm -f main.o Out.txt