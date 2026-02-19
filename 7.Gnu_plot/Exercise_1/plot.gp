
set title "Eror function"
set xlabel "X"
set ylabel "Err(x)"
set grid
set key outside

set output "printme.pdf"
plot "Ouput_data.txt"  using 1:2 linewidth 2 title "Computed errorfunction", \
"Error_function_data.txt" using 1:2 with lines linewidth 2 title "Table valoues"

pause -1
