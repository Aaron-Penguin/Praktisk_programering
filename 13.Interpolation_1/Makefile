CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20
Objekts = main.o

all: out.txt


out.txt: main
	./main > $@


x_data = 1 2 3 4 5

test_data.txt:
	2 >> $@



# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.pdf
