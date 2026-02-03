Out.txt : math_stuf             # Out.txt depends on math_stuff.exe
	./math_stuf > Out.txt        # run math_stuf.exe, send output to Out.txt
math_stuf: Calculating_in_cpp.cc                 # hello depends on hello.cc
	c++ -o math_stuf Calculating_in_cpp.cc  # compile-and-link hello.cc, save executable in
clean:
	rm -f Out.txt math_stuf