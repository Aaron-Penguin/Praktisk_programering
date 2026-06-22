set terminal png
set title "Convergence of dr"
set xlabel "dr"
set ylabel "E [Hartree]"
set grid
set key outside

set xrange [0:6]
set yrange [-0.6:0]
set size square 1.0,1.0

set linetype 1 lw 2 lc rgb "red" pointtype 1

plot "Testing_dr.txt" using 1:2 with points title "Lowest energy state"
pause -1