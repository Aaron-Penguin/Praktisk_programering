CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Objekts = main.o Matrix.o QR.o 

out.txt: main
	./main > $@

# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.png