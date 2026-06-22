set terminal pdf
set title "Evaluating erf(x) with numeric integration"
set xlabel "x"
set ylabel "y"
set grid
set key outside

set xrange [-5:5]
set yrange [-2.5:2.5]
set size square 1.0,1.0

set linetype 1 lc rgb "red"
set pointsize 0.3


plot "Error_func.txt" using 1:2 title "erf(x), our solution",\
"Table_of_erf(x)_from_wiki.txt" using 1:2 title "erf(x), table valoues from wiki"
pause -1