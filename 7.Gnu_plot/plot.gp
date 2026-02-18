
set title "Eror function"
set xlabel "X"
set ylabel "Err(x)"
set grid

plot "Error_function_data.txt" using 1:2 with linespoints title "Measurement"
pause -1