set terminal pdf
set title "224-Ra decay"
set xlabel "t [days]"
set ylabel "ln(Activity) [relative units]"
set grid
set key outside

set xrange [0:18]
set yrange [0:6]
set size square 1.0,1.0

set linetype 1 lc rgb "red
set pointsize 0.3


plot "Data.txt" using 2:4:6 w yerrorbars title "Measured decay",\
"Fit_data.txt" using 1:2 with lines title "fit"
pause -1