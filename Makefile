CFLAGS := -Wall -O3
PROGRAM=test_ecosys ecosys
all: tests_ecosys ecosys

main_tests.o: main_tests.c
	gcc $(CFLAGS) -c main_tests.c

ecosys.o: ecosys.c ecosys.h
	gcc $(CFLAGS) -c ecosys.c ecosys.h

tests_ecosys : main_tests.o ecosys.o
	gcc $(CFLAGS) -o tests_ecosys main_tests.o ecosys.o

main_ecosys.o :  main_ecosys.c
	gcc $(CFLAGS) -c main_ecosys.c

ecosys: ecosys.o main_ecosys.o
	gcc $(CFLAGS) -o ecosys main_ecosys.o ecosys.o 


clean:
	rm -f *.o *.gch $(PROGRAMS)
