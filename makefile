cc=mpicc

all: block_ping_pong nonblock_ping_pong block_ring nonblock_ring

# Non-block Ring
nonblock_ring: nonblock_ring.o
	$(cc) nonblock_ring.o -o nonblock_ring

nonblock_ring.o: nonblock_ring.c
	$(cc) -c nonblock_ring.c -o nonblock_ring.o

# Block Ring
block_ring: block_ring.o
	$(cc) block_ring.o -o block_ring

block_ring.o: block_ring.c
	$(cc) -c block_ring.c -o block_ring.o

# Non-block Pingpong
nonblock_ping_pong: nonblock_ping_pong.o
	$(cc) nonblock_ping_pong.o -o nonblock_ping_pong

nonblock_ping_pong.o: nonblock_ping_pong.c
	$(cc) -c nonblock_ping_pong.c -o nonblock_ping_pong.o

# Block Pingpong
block_ping_pong: block_ping_pong.o
	$(cc) block_ping_pong.o -o block_ping_pong

block_ping_pong.o: block_ping_pong.c
	$(cc) -c block_ping_pong.c -o block_ping_pong.o

