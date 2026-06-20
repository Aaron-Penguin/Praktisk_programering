set terminal pdf
set title "MC integration"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set logscale xz
set logscale y
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "out.txt" using 1:3 with lines title "Estimated Error",\
"out.txt" using 1:4 with lines title "Actual Error"
pause -1