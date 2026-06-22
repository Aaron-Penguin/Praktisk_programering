set terminal png
set title "Lowest energy wavefunctions of hydrogen"
set xlabel "r [Bohr radius]"
set ylabel "Wavefunction f(r)"
set grid
set key outside

set xrange [0:15]
set size square 1.0,1.0

# set linetype 1 lw 2 lc rgb "red" pointtype 1

plot "wave_func.txt" using 2:3 with lines title "Analytic R_0(r)", \
"wave_func.txt" using 2:4 with lines title "Analytic R_1(r)" ,\
"wave_func.txt" using 2:5 with points pointtype 1 title "Numeric R_0(r)", \
"wave_func.txt" using 2:6 with points pointtype 1 title "Numeric R_1(r)",
pause -1