CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o Matrix.o QR.o Predictor.o

all: data.txt


sample.txt: main
	./main -printtype Sample > $@

fit.txt: main
	./main -printtype fit > $@


plot.pdf: main Makefile sample.txt fit.txt
	gnuplot plot.gp > $@

# ---- Colpiling and linking --------
main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
