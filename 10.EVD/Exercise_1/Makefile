CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

out.txt: main
	./main > out.txt


main: main.o Matrix.o EVD.o
	$(CXX) -o main main.o Matrix.o EVD.o


# Compiling

main.o: main.cc Matrix.h
	$(CXX) $(CXXFLAGS) -c main.cc

EVD.o: EVD.cc EVD.h
	$(CXX) $(CXXFLAGS) -c EVD.cc


Matrix.o: Matrix.cc Matrix.h
	$(CXX) $(CXXFLAGS) -c Matrix.cc


# Vector.o: Vector.cc Vector.h
# 	$(CXX) $(CXXFLAGS) -c Vector.cc


# EVD.o: EVD.cc EVD.h
# 	$(CXX) $(CXXFLAGS) -c EVD.cc
#  -----------------------


clean:
	rm -f main *.o main out.txt

# plot: Makefile out.times.data.txt
# 	gnuplot plot.gp


# fig1.png: Makefile out.times.data.txt
# 	gnuplot -e "set terminal pngcairo size 800,600; set output 'fig1.png'" plot.gp