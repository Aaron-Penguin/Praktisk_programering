(Project 13) -- Least-squares signal extrapolation (linear prediction)

The final result of the implementation of the linear prediction, is shown in "plot.pdf".
Only the points with x < 1, are used as input for the fitting.

The "Matrix.cc" and "QR.cc" files and there header files, are
copys from the Homework exercise folder "9.Linear_eq" of my repository.

"Matrix.cc" gives the fundamental class that is implemented in "QR.cc", for QR-decomposition.
"Predictor.cc" includes the function that makes linear prediction and it includes "QR.cc" as well as "Matrix.cc".
"function.cc" includes just an example function used for sampling and fitting. This function is visualised as plot in "plot.pdf". 

"sample.txt" includes the data, by direct evaluation of the function. (First colum = x_data;  Second colum = y_data)
"fit.txt"  includes the data point, found through extrapolation. (First colum = x_data;  Second colum = y_data)