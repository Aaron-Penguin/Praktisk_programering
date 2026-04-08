CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Objekts = main.o Matrix.o Vector.o EVD.o Quicksort.o

out.txt: main
	./main > out.txt


main: $(Objekts) 
	$(CXX) -o main $(Objekts)


# Compiling
# main.o: main.cc Matrix.h
# 	$(CXX) $(CXXFLAGS) -c main.cc

$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@


clean:
	rm -f main *.o main out.txt

# plot: Makefile out.times.data.txt
# 	gnuplot plot.gp


# fig1.png: Makefile out.times.data.txt
# 	gnuplot -e "set terminal pngcairo size 800,600; set output 'fig1.png'" plot.gp