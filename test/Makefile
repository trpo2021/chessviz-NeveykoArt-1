CCFLAGS=-Wall -Wextra -Wconversion -Wredundant-decls -Wshadow -Wno-unused-parameter -O3


all: test

%.cpp: %.c
	ln -fs $< $@

mytest.c.o: mytest.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

main_test.c.o: main_test.c ctest.h
	$(CC) $(CCFLAGS) -c -o $@ $<

test: main_test.c.o ctest.h mytest.c.o
	$(CC) $(LDFLAGS) main_test.c.o mytest.c.o -o test ../obj/src/libchessviz/libchessviz.a

clean:
	rm -f test *.o

