FLAGS= -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPTIMIZE= -O3

all: a01.out a02.out a03.out a04.out a07.out a08.out a09.out

func.o: func.c func.h
	gcc -c $(FLAGS) $(OPTIMIZE) func.c

task01.o: task01.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task01.c
a01.out: task01.o func.o
	gcc task01.o func.o -lm -o a01.out

task02.o: task02.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task02.c
a02.out: task02.o func.o
	gcc task02.o func.o -lm -o a02.out

task03.o: task03.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task03.c
a03.out: task03.o func.o
	gcc task03.o func.o -lm -o a03.out

task04.o: task04.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task04.c
a04.out: task04.o func.o
	gcc task04.o func.o -lm -o a04.out

task07.o: task07.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task07.c
a07.out: task07.o func.o
	gcc task07.o func.o -lm -o a07.out

task08.o: task08.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task08.c
a08.out: task08.o func.o
	gcc task08.o func.o -lm -o a08.out

task09.o: task09.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task09.c
a09.out: task09.o func.o
	gcc task09.o func.o -lm -o a09.out

clean:.
	rm -f *.out *.o