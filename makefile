cc=mpicc

all: blocking_ping_pong nonblock_ping_pong

nonblock_ping_pong: nonblock_ping_pong.o
	$(cc) nonblock_ping_pong.o -o nonblock_ping_pong

nonblock_ping_pong.o: nonblock_ping_pong.c
	$(cc) -c nonblock_ping_pong.c -o nonblock_ping_pong.o

blocking_ping_pong: blocking_ping_pong.o
	$(cc) blocking_ping_pong.o -o blocking_ping_pong

blocking_ping_pong.o: blocking_ping_pong.c
	$(cc) -c blocking_ping_pong.c -o blocking_ping_pong.o

