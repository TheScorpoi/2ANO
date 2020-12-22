CC = gcc

CFLAGS = -Wall

LDFLAGS = -lm

.PHONY: all clean cleanall

all: server client 

comm-shm.o:	comm.h semaphore.h sharedMemory.h

server client:	%:	%.o sharedMemory.o semaphore.o comm-shm.o
	gcc ${CFLAGS} -o $@ $? ${LDFLAGS}

clean:
	rm -f *.o *~

cleanall:	clean
	rm -f server client 

