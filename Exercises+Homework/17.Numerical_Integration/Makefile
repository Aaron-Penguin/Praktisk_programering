CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o Integrate.o Functions.o

all: Test_integrals.txt Error_func.txt

Test_integrals.txt: main
	./main -printtype Test_integrator > $@

Error_func.txt: main
	./main -printtype Err_func > $@

Testing_acc.txt: main
	./main -printtype Test_acc > $@


plot.pdf: main Makefile Error_func.txt plot.gp
	rm -f $@
	gnuplot plot.gp > $@

plot2.pdf: main Makefile Testing_acc.txt plot2.gp
	rm -f $@
	gnuplot plot2.gp > $@


# ---- Colpiling and linking --------
main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
