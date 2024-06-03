executable: objex
	cc *.o -o spacez

objex:
	cc -c src/*.c main.c

clean:
	rm *.o spacez
