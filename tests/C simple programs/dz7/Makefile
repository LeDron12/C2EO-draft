FLAGS= -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPTIMIZE= -O3

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out

matrix.o: matrix.c matrix.h
	gcc -c $(FLAGS) $(OPTIMIZE) matrix.c

task01.o: task01.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task01.c
a01.out: task01.o matrix.o
	gcc task01.o matrix.o -lm -o a01.out

task02.o: task02.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task02.c
a02.out: task02.o matrix.o
	gcc task02.o matrix.o -lm -o a02.out

task03.o: task03.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task03.c
a03.out: task03.o matrix.o
	gcc task03.o matrix.o -lm -o a03.out

task04.o: task04.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task04.c
a04.out: task04.o matrix.o
	gcc task04.o matrix.o -lm -o a04.out

task05.o: task05.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task05.c
a05.out: task05.o matrix.o
	gcc task05.o matrix.o -lm -o a05.out

task06.o: task06.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task06.c
a06.out: task06.o matrix.o
	gcc task06.o matrix.o -lm -o a06.out

task07.o: task07.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task07.c
a07.out: task07.o matrix.o
	gcc task07.o matrix.o -lm -o a07.out

clean:
	rm -f *.o *.out