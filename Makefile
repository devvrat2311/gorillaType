executable: objex
	cc *.o -o gorillaType

objex:
	cc -c src/*.c main.c

clean:
	rm *.o gorillaType 
