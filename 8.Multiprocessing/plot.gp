set terminal png
set title "Harmonic sum multithreating"
set xlabel "N threads used"
set ylabel "Time [s]"
set grid
set key outside

set xrange [0:9]
set yrange [0:10]

set linetype 1 lw 2 lc rgb "red" pointtype 1

plot "out.times.txt" using 1:2 with points title "Computation time"
pause -1