/* decToBinary.c
 * Yunyi Ding
 * Prof. Helmbold
 * 4/1/2014
 */

/* decToBinary.c is the main program that performs the operation.
 * Objective/Purpose:
 *     1. Read a user's input: an integer
 *     2. Determine if the input is a non-negative interger
 *         if it is a negative integer, print error msg and quit
 *     3. If the input is legal (0 or positive integers)
 *         if it is 0, put 0 onto the stack created
 *         else 
 *         while the number is greater than 0,
 *         	if the positive integer is odd, push 1 onto the stack
 *         	else push 0 onto the stack
 *         	number=number/2
 *     4. Print out the binary value of the decimal value of the integer
 *
 * Help:
 * 	Textbook and Handouts
 */

#include "myinclude.h"
#include "intstack.h"

int main(){
/* declare a integer num */
	int num;
/* create an empty stack */
/* new pointer */
	StackHndl MyStack;
/* set the pointer to null */
	MyStack=NULL;
/* new empty stack */
	MyStack=NewStack();
/* print out greeting and prompt */
	printf("Welcome! Please Enter a Positive Decimal Integer: ");
/* read in user's input and print it out */
	scanf("%d", &num);
	
/* if the input is less than 0, print out the error message */
	 if(num<0){
            printf("This is not a NON-NEGATIVE integer.\n");
        }else{
	/* if the input is equal to 0, just put 0 onto the stack */
	if(num==0){
		Push(MyStack,0);
	}
	/* print a line to say what input is it */
	printf("Decimal %d is ", num);
	/* if the input is a positive integer, create a loop */
	while(num>=1){
	/* if the remainder of num divided by 2 is not 0, the num is odd */
	/* if the num is odd, push 1 onto the stack */
		if(num%2!=0){
			Push(MyStack,1);
		}else{
	/* if the remainder of num divided by 2 is 0, the num is even */
	/* if the num is even, push 0 onto the stack */
			Push(MyStack,0);
		}
	/* num then equals to num/2 */
	/* keep looping until num reaches 0 */
		num=num/2;
	}
	
	/* while the stack is not empty, print data on the stack out one by
	 * one and pop each of them until the stack is null
	 */
	while(!IsEmpty(MyStack)){
		printf("%d",Top(MyStack));
		Pop(MyStack);
	}
	/* print out binary result */
	printf(" in binary.\n");
	}
	/* when the operation is done (/invalid input value),
	 * terminate
	 */
	return(0);
}
