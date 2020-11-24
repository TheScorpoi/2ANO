
CC = gcc
CFLAGS = -Wall

progs = fork1 fork2 child fork3 fork4 sig1 sig2
objs = $(progs:%=%.o)

.PHONY:     all clean cleanall

all:		$(progs)

$(progs):	%:	%.o
	$(CC) -o $@ $<

$(objs):	%.o:	%.c
	$(CC) $(CFLAGS) -c -o $@ $<

clean:
	rm -f *~ *.o

cleanall:	clean
	rm -f $(progs) 
