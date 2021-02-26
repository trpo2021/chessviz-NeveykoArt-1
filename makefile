all: chessviz

chessviz: chessviz.o
	gcc -Wall -Werror chessviz.o -o chessviz

chessviz.o: chessviz.c
	gcc -Wall -Werror -c chessviz.c

clean:
	rm -rf *.o
