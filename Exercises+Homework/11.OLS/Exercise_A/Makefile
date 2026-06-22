CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o Matrix.o QR.o OLS.o

Text_files = Testing.txt Fit_params.txt Fit_data.txt Data.txt Half_life.txt


all: $(Text_files) plot.pdf

plot.pdf: main Makefile plot.gp Data.txt Fit_data.txt
	rm -f $@
	gnuplot plot.gp > $@


# --- Text files ---------


Testing.txt: main
	./main -printtype Test_QR > $@


Fit_params.txt: main
	./main -printtype Fit > $@

Fit_data.txt: main Fit_params.txt
	./main -printtype Fit_sample --input Fit_params.txt --output $@

Data.txt: main 
	./main -printtype Print_data > $@


Half_life.txt: main Fit_params.txt
	./main -printtype Find_half-life > $@


# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
