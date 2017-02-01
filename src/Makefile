OBJS = BitMap.o Mandelbrot.o main.o 
CC = g++
DEBUG = -g
CFLAGS = -std=c++11 -Wall -c $(DEBUG)
LFLAGS = -Wall $(DEBUG)

all: fractal

fractal: $(OBJS)
	$(CC) $(LFLAGS) -o $(OBJS)

main.o: BitMap.h Mandelbrot.h BitMapFileHeader.h BitMapInfoHeader.h
	$(CC) $(CFLAGS) main.cpp

BitMap.o: BitMap.h BitMapInfoHeader.h BitMapFileHeader.h
	# $(CC) $(CFLAGS) BitMap.cpp

Mandelbrot.o: Mandelbrot.h
	$(CC) $(CFLAGS) Mandelbrot.cpp

clean:
	\rm *.o *~ fractal

tar:
	tar cfv fractal.tar src/BitMap.h src/BitMap.cpp src/Mandelbrot.cpp src/BitMapFileHeader.h src/BitMapInfoHeader.h src/Mandelbrot.h