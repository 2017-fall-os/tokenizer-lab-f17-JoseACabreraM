test: test.o myToc.o
  cc -o test test.o myToc.o
  
CFLAGS=-g -O3

myToc.o: myToc.c
  cc -c myToc.c
  
test.o: test.c myToc.h
  cc -c test.o

clean:
	rm -f *.o 
