cc=mpicc

pingpong: main.o
	$(cc) main.o -o pingpong

main.o: main.c
	$(cc) -c main.c -o main.o