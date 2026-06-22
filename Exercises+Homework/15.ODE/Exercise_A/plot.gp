set terminal pdf
set title "Solving: u''(x) = -u(x)"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set xrange [0:10]
set yrange [-2.5:2.5]
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "SHO.txt" using 1:2 title "SHO",\
"HO_friction.txt" using 1:2 title "HO with friction"
pause -1