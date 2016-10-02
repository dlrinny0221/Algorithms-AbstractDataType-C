linkedlistdr : linkedlistdr.o linkedlist.o
	gcc -ansi -Wall -Wextra -pedantic -o linkedlistdr linkedlistdr.o linkedlist.o

linkedlist.o : linkedlist.h linkedlist.c
	gcc -c -ansi -Wall -Wextra -pedantic linkedlist.c

linkedlistdr.o : linkedlist.h linkedlistdr.c
	gcc -c -ansi -Wall -Wextra -pedantic linkedlistdr.c

clean :
	rm linkedlistdr linkedlistdr.o linkedlist.o
