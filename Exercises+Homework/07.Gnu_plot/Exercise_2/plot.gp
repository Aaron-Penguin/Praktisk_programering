set title "gamma function"
set xlabel "X"
set ylabel "Gamma(x)"
set grid
set key outside

set xrange [-5:5]
set yrange [-5:25]

set linetype 1 lw 2 lc rgb "red" pointtype 1

plot "out.txt" using 1:2 with lines title "Computed gammafunction", \
"out.txt" using 1:3  with points title "Stirlings approximation"
pause -1