set terminal png
set title "Convergence of r max"
set xlabel "r max"
set ylabel "E [Hartree]"
set grid
set key outside

set xrange [0:25]
set yrange [-0.6:0]
set size square 1.0,1.0

set linetype 1 lw 2 lc rgb "red" pointtype 1

plot "Testing_rmax.txt" using 1:2 with points title "Lowest energy state"
pause -1