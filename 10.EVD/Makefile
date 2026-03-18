CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20


out.times.data.txt: main Makefile
	>$@
	for N in $$(seq 100 20 500); do \
		time --format "$$N %e" --output $@ --append \
		./$< -size $$N 1>out 2>err ;\
	done


# Linking into file main

main: main.o Matrix.o QR.o
	$(CXX) -o main main.o Matrix.o QR.o

#  Compiling seperate c++ files

main.o: main.cc Matrix.h QR.h
	$(CXX) $(CXXFLAGS) -c main.cc

Matrix.o: Matrix.cc Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cc

QR.o: QR.cc Matrix.h QR.h
	$(CXX) $(CXXFLAGS) -c QR.cc
#  -----------------------


clean:
	rm -f *.o main err out out.times.data.txt fig1.png fit.log


plot: Makefile out.times.data.txt
	gnuplot plot.gp


fig1.png: Makefile out.times.data.txt
	gnuplot -e "set terminal pngcairo size 800,600; set output 'fig1.png'" plot.gp