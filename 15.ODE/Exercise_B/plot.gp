set terminal pdf
set title "Equation of motion of a planet in orbit around a star"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set xrange [-3:3]
set yrange [-3:3]
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "Newtonian_circular.txt" using 1:2 with lines title "Newtonian circular",\
"Newtonian_elipse.txt" using 1:2 with lines title "Newtonian elliptical",\
"GR.txt" using 1:2 with lines title "Relativistic precession"
pause -1