set terminal pdf
set title "Interpolation"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set xrange [0:9]
set yrange [-2.5:2.5]
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "Data.txt" using 1:2 title "f(x) = Sin(x)",\
"Interp.txt" using 1:2 with lines title "Linear spline",\
"Interp.txt" using 1:3 with lines title "Integrated Lin-spline",\
"qspline.txt" using 1:2 linetype 2 linecolor 4 with lines title "Quadratic spline",\
"qspline.txt" using 1:3 linetype 2 linecolor 5 with lines title "Quadratic spline Integrated"
pause -1