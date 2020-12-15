CC = gcc
CFLAGS = -Wall

LK = gcc
LDFLAGS = -lpthread -lm

.PHONY: clean cleanall

objs = incMod.o incModSafe.o incrementer.o

incrementer:    incrementer.o incMod.o
		$(LK) -o $@ $^ $(LDFLAGS)

incrementerSafe:incrementer.o incModSafe.o
		$(LK) -o $@ $^ $(LDFLAGS)

$(objs):	%.o:	%.c incMod.h
		$(CC) $(CFLAGS) -c -o $@ $<

clean:
		rm -f *.o *~

cleanall:	clean
		rm -f incrementer incrementerSafe
