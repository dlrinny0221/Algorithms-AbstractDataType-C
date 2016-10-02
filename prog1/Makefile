# Yunyi Ding
# Makefile
# Prof. Helmbold
# 4/1/2014
# This Makefile file is created based on the Makefile that was given
# Basically, I changed all intstackdr to decToBinary
#
decToBinary : decToBinary.o intstack.o
	gcc -ansi -Wall -Wextra -pedantic -o decToBinary decToBinary.o intstack.o

intstack.o : intstack.h intstack.c
	gcc -c -ansi -Wall -Wextra -pedantic intstack.c

decToBinary.o : intstack.h decToBinary.c
	gcc -c -ansi -Wall -Wextra -pedantic decToBinary.c

clean :
	rm decToBinary decToBinary.o intstack.o

