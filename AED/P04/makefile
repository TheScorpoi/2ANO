#
# Tomás Oliveira e Silva, AED, September 2020
#
# makefile to compile all programs for the AED P.04 computer lab class
#

clean:
	rm -f a.out
	rm -f functions solution_functions
	rm -f solution_fusc
	rm -f find_pairs solution_find_pairs


#
# $^ gets replaced by the list of dependencies (prerequisites)
#

functions:		functions.c
	cc -Wall -O2 $^ -o $@

functions_extra:	functions_extra.c
	cc -Wall -O2 $^ -o $@

solution_functions:	solution_functions.c
	cc -Wall -O2 $^ -o $@


solution_fusc:		solution_fusc.c
	cc -Wall -O2 $^ -o $@


find_pairs:		find_pairs.c
	cc -Wall -O2 $^ -o $@
