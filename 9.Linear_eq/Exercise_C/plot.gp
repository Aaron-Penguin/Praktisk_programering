set title "Computation time of QR facorization"
set xlabel "N"
set ylabel "time [s]"
set grid
set key outside

# set xrange [0:250]
# set yrange [0:2]

set fit errorvariables

f(x) = a*x**3
fit f(x) 'out.times.data' using 1:2 via a


set linetype 1 lw 2 lc rgb "red" pointtype 1
plot "out.times.data" using 1:2 with points title "QR factorization",\
f(x)
pause -1