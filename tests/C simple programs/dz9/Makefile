FLAGS= -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPTIMIZE= -O3

all: a01.out a02.out a03.out a05.out a06.out a07.out a08.out

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

task05.o: task05.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task05.c
a05.out: task05.o func.o
	gcc task05.o func.o -lm -o a05.out

task06.o: task06.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task06.c
a06.out: task06.o func.o
	gcc task06.o func.o -lm -o a06.out

task07.o: task07.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task07.c
a07.out: task07.o func.o
	gcc task07.o func.o -lm -o a07.out

task08.o: task08.c func.h
	gcc -c $(FLAGS) $(OPTMIZE) task08.c
a08.out: task08.o func.o
	gcc task08.o func.o -lm -o a08.out

clean:.
	rm -f *.out *.o