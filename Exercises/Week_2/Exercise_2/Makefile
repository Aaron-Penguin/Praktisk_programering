Out.txt : Run_code                             # Out.txt depends on math_stuff.exe
	./Run_code > Out.txt                         # run math_stuf.exe, send output to Out.txt
Run_code: Gamma_func.cc                 # hello depends on hello.cc
	c++ -o Run_code Gamma_func.cc        # compile-and-link hello.cc, 
clean:
	rm -f Out.txt Run_code