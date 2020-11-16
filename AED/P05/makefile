#
# makefile to compile all programs for the AED P.05 computer lab class
#

clean:
	rm -f examples selection a.out


examples:	examples.c
	cc -Wall -O2 examples.c -o $@ -lm


selection:	selection.c
	cc -Wall -O2 selection.c -o $@ -lm

solution_selection:	solution_selection.c
	cc -Wall -O2 solution_selection.c -o $@ -lm
