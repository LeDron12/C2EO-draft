FLAGS= -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPTIMIZE= -O3

all: a01.out a02.out a03.out a04.out a05.out a06.out a07.out a08.out a09.out a10.out a11.out

matrix.o: matrix.c matrix.h
	gcc -c $(FLAGS) $(OPTIMIZE) matrix.c

task01.o: task01.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task01.c
a01.out: task01.o matrix.o
	gcc task01.o matrix.o -o a01.out

task02.o: task02.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task02.c
a02.out: task02.o matrix.o
	gcc task02.o matrix.o -o a02.out

task03.o: task03.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task03.c
a03.out: task03.o matrix.o
	gcc task03.o matrix.o -o a03.out

task04.o: task04.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task04.c
a04.out: task04.o matrix.o
	gcc task04.o matrix.o -o a04.out

task05.o: task05.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task05.c
a05.out: task05.o matrix.o
	gcc task05.o matrix.o -o a05.out

task06.o: task06.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task06.c
a06.out: task06.o matrix.o
	gcc task06.o matrix.o -o a06.out

task07.o: task07.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task07.c
a07.out: task07.o matrix.o
	gcc task07.o matrix.o -o a07.out

task08.o: task08.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task08.c
a08.out: task08.o matrix.o
	gcc task08.o matrix.o -o a08.out

task09.o: task09.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task09.c
a09.out: task09.o matrix.o
	gcc task09.o matrix.o -o a09.out

task10.o: task10.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task10.c
a10.out: task10.o matrix.o
	gcc task10.o matrix.o -o a10.out

task11.o: task11.c matrix.h
	gcc -c $(FLAGS) $(OPTMIZE) task11.c
a11.out: task11.o matrix.o
	gcc task11.o matrix.o -o a11.out


clean:
	rm -f *.o *.out