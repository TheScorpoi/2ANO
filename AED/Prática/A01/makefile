#
# Tomás Oliveira e Silva, AED, October 2020
#
# makefile to compile the A.02 practice work
#

clean:
	rm -fv a.out
	rm -fv job_selection

veryclean:	clean
	rm -rfv [0-9][0-9][0-9][0-9][0-9][0-9]


job_selection:	job_selection.c rng.c
	cc -Wall -O2 job_selection.c -o job_selection -lm
