CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o binsearch.o Linear_spline.o qspline.o

all: plot.pdf

Data.txt: main
	./main -printtype Construct_data > $@

Interp.txt: main
	./main -printtype Spline_data > $@

qspline.txt: main
	./main -printtype Qspline_data > $@


plot.pdf: main Makefile Data.txt Interp.txt qspline.txt plot.gp
	rm -f $@
	gnuplot plot.gp > $@



# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
