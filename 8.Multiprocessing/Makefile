CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Out.txt : main             # Creating an txt file for the output
	./main > out.txt

main: main.o
	$(CXX) main.o -o main

main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc

clean:
	rm -f main.o Out.txt

TIME = time --format "$$N_threads %e %U" --append --output $@
out.times.txt : main Makefile
	>$@
	for N_threads in 1 2 3 4 5 6 7 8; do \
		$(TIME) ./main -N_threads $$N_threads;\
	done