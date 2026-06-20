CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o MC.o

all: plot.pdf


plot.pdf:Makefile main Circle.txt plot.gp
	gnuplot plot.gp > $@

Circle.txt: main
	./main -printtype Area_of_hafe_circle > $@

Epsiloid.txt: main
	./main -printtype Volume > $@

# ---- Colpiling and linking --------
main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
