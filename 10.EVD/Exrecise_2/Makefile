CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++20

Objekts = main.o Matrix.o EVD.o   # Quicksort.o  Vector.o

r_valoues := 4 3 2 1 0.5 0.2 0.1 0.05
r_max_vals := 2 5 10 15 20

all: main fig1.png fig2.png wave_func_plot.png

# ---- Colpiling and linking --------

main: $(Objekts)
	$(CXX) -o main $(Objekts)


$(Objekts): %.o: %.cc
	$(CXX) $(CXXFLAGS) -c $^ -o $@

# ---------------------

clean:
	rm -f main *.o *.txt *.png




Testing_dr.txt : main Makefile
	@rm -f $@
	for dr in $(r_valoues); do \
	./main -dr $$dr -rmax 15 -printtype dr_input >> $@;\
	done


fig1.png: Makefile Testing_dr.txt plot_test_dr.gp
	gnuplot plot_test_dr.gp > fig1.png


Testing_rmax.txt: main Makefile
	@rm -f $@
	for Rmax in $(r_max_vals); do \
	./main -dr 0.05 -rmax $$Rmax -printtype rmax_input >> $@;\
	done

fig2.png: Makefile Testing_rmax.txt plot_test_rmax.gp
	@rm -f $@
	gnuplot plot_test_rmax.gp > fig2.png


wave_func.txt: main Makefile
	rm -f $@
	./main -dr 0.1 -rmax 15 -printtype wave_function >> $@

wave_func_plot.png: Makefile wave_func.txt plot_wave.gp
	rm -f $@
	gnuplot plot_wave.gp > $@




# fig1.png: Makefile out.times.data.txt
# 	gnuplot -e "set terminal pngcairo size 800,600; set output 'fig1.png'" plot.gp