calculator: main.o my_stack.o getop.o my_get.o
	gcc -o calculator main.o my_stack.o my_get.o getop.o

main.o: main.c
	gcc -c main.c
my_stack.o: my_stack.c
	gcc -c my_stack.c
my_get.o: my_get.c
	gcc -c my_get.c
getop.o: getop.c
	gcc -c getop.c

clean:
	rm main.o my_get.o my_stack.o getop.o calculator
