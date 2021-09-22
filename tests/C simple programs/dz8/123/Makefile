FLAGS= -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs
OPTIMIZE= -O3

all: a.out 

matrix.o: matrix.c matrix.h
	gcc -c $(FLAGS) $(OPTIMIZE) matrix.c
solve.o: solve.c solve.h
	gcc -c $(FLAGS) $(OPTIMIZE) solve.c

task.o: task.c matrix.h solve.h
	gcc -c $(FLAGS) $(OPTMIZE) task.c
a.out: task.o matrix.o solve.o
	gcc task.o matrix.o solve.o -lm -o a.out

clean:.
	rm -f *.out *.o *.out.stackdump