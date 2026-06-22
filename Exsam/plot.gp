set terminal pdf
set title "Least-squares signal extrapolation"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set xrange [0:2]
set yrange [-8:8]
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "sample.txt" using 1:2 title "Signal with no noise",\
"fit.txt" using 1:2 with lines title "Extrapolated fit"
pause -1