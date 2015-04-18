target=wordscount
${target}: addtree.o getword.o main.o talloc.o my_get.o
	gcc -o ${target} addtree.o getword.o main.o talloc.o my_get.o

addtree.o: addtree.c
	gcc -c addtree.c

getword.o: getword.c
	gcc -c getword.c

main.o: main.c
	gcc -c main.c 

talloc.o: talloc.c
	gcc -c talloc.c

my_get.o: my_get.c
	gcc -c my_get.c

clean:
	rm talloc.o main.o getword.o addtree.o my_get.o ${target}

