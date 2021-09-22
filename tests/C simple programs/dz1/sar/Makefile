FLAGS = -mfpmath=sse -fstack-protector-all -W -Wall -Wextra -Wunused -Wcast-align -Werror -pedantic -pedantic-errors -Wfloat-equal -Wpointer-arith -Wformat-security -Wmissing-format-attribute -Wformat=1 -Wwrite-strings -Wcast-align -Wno-long-long -std=gnu99 -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wold-style-definition -Wdeclaration-after-statement -Wbad-function-cast -Wnested-externs 
OPT = -O3 
all: a01.out a02.out a03.out a04.out a05.out
%.o: %.c 
	gcc -c $(FLAGS) $(OPT) $< 
%.out: %.o 
	gcc $(FLAGS) $^ -o $@ 
 
functions.o: functions.c
 
a01.out: a01.o functions.o  
a01.o: a01.c
 
a02.out: a02.o functions.o  
a02.o: a02.c
 
a03.out: a03.o functions.o  
a03.o: a03.c
 
a04.out: a04.o functions.o  
a04.o: a04.c
 
a05.out: a05.o functions.o  
a05.o: a05.c
 
clean: 
	rm -f *.out *.o
