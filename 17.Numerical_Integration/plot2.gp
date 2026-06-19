set terminal pdf
set title "Evaluating erf(1) with numeric integration"
set xlabel "accuracy"
set ylabel "y"
set grid
set key outside

set logscale xz

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "Testing_acc.txt" using 1:2 with lines title "erf(1)"
pause -1