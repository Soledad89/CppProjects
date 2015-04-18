target=funcpointer
${target}: main.o my_qsort.o numcmp.o readline.o
	gcc -o ${target} main.o my_qsort.o numcmp.o readline.o

main.o: main.c
	gcc -c main.c
my_qsort.o: my_qsort.c
	gcc -c my_qsort.c
numcmp.o: numcmp.c
	gcc -c numcmp.c
readline.o: readline.c
	gcc -c readline.c

clean:
	rm numcmp.o main.o my_qsort.o readline.o ${target}
