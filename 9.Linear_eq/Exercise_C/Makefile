CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objects = Matrix.o main.o 

Out.txt : main             # Creating an txt file for the output
	./main > Out.txt

main: main.o
	$(CXX) main.o -o main


main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o


clear:
	rm -f *.o Out.txt main

out.times.data : main Makefile
	>$@
	for N in $$(seq 100 20 200); do \
		time --format "$$N %e" --output $@ --append \
		./$< -size $$N 1>out 2>err ;\
	done 





