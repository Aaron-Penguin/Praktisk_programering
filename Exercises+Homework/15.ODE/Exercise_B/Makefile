CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o RK12.o Driver.o

all: SHO.txt HO_friction.txt plot.pdf

# Data.txt: main
# 	./main > $@


Newtonian_circular.txt: main
	./main -printtype Solver_1 > $@

Newtonian_elipse.txt: main
	./main -printtype Solver_2 > $@

GR.txt: main
	./main -printtype Solver_3 > $@


# HO_friction.txt: main
# 	./main -printtype Solver_2 > $@


plot.pdf: main Makefile Newtonian_circular.txt Newtonian_elipse.txt GR.txt plot.gp
	gnuplot plot.gp > $@


# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
