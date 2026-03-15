CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objects = Matrix.o main.o 


out.times.data : main Makefile
	>$@
	for N in $$(seq 100 20 500); do \
		time --format "$$N %e" --output $@ --append \
		./$< -size $$N 1>out 2>err ;\
	done 


main: main.o
	$(CXX) main.o -o main


main.o: main.cc
	$(CXX) $(CXXFLAGS) -c main.cc -o main.o


clear:
	rm -f *.o main err out out.times.data


fig1.png: Makefile out.times.data
	gnuplot plot.gp > fig1.png

plot: out.times.data
	gnuplot plot.gp



