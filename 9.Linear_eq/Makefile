CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objects = Matrix.o main.o 

Out.txt : main             # Creating an txt file for the output
	./main > Out.txt

main: main.o
	$(CXX) main.o -o main


main.o: main.cc
	$(CXX) -c main.cc -o main.o

# $(Objects): %.o: %.cc
# 	$(CXX) $(CXXFLAGS) -c $^ -o $@



clear:
	rm -f *.o Out.txt main





