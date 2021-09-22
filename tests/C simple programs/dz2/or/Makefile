FLAGS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs -fnon-call-exceptions

#OPT = -O3

all: a01.out a02.out a03.out a04.out a05.out


%.o : %.c 
	gcc -g -c $(FLAGS) $(OPT) $<


a01.out: main01.o funcs.o
	gcc main01.o funcs.o -o a01.out
main01.o: main01.c funcs.h
functions.o: funcs.c funcs.h

a02.out: main02.o funcs.o
	gcc main02.o funcs.o -o a02.out	
main02.o: main02.c funcs.h
functions.o: funcs.c funcs.h

a03.out: main03.o funcs.o
	gcc main03.o funcs.o -o a03.out	
main03.o: main03.c funcs.h
functions.o: funcs.c funcs.h

a04.out: main04.o funcs.o
	gcc main04.o funcs.o -o a04.out	
main04.o: main04.c funcs.h
functions.o: funcs.c funcs.h

a05.out: main05.o funcs.o
	gcc main05.o funcs.o -o a05.out	
main05.o: main05.c funcs.h
functions.o: funcs.c funcs.h

clean:
	rm -f *.o *.out

