CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o

all: Data.txt

Data.txt: main
	./main -printtype Construct_data > $@

Interp.txt: main
	./main -printtype Spline_data > $@


plot.pdf: main Makefile Data.txt Interp.txt plot.gp
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
