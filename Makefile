OBJS = BitMap.o main.o 
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: fractal

fractal: $(OBJS)
	$(CC) $(LFLAGS) $(OBJS) -o fractal

BitMap.o: BitMap.h
	$(CC) $(CFLAGS) BitMap.cpp

main.o: BitMap.h
	$(CC) $(CFLAGS) main.cpp

clean:
	\rm *.o *~ fractal

tar:
	tar cfv fractal.tar BitMap.h BitMap.cpp BitMapFileHeader.h BitMapInfoHeader.h