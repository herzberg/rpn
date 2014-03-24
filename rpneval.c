//Josh Herzberg
//See: https://en.wikipedia.org/wiki/Reverse_Polish_notation

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define PI 3.1415
#include "rpneval.h"

static double STACK[STACKSIZE]; //STACKSIZE defined in header file.
static double *SP = &STACK[0] - 1;  //stack pointer - 1 char below so first push will happen in right location.



int eval_rpn(double *result, char *expr)
{


char firstletter = 1; 
double a,b,c; //just variables to do operations with.
char *pc;
pc = expr;
	while(*pc != '\0')
	{
		if(*(pc -1) == ' ' || *(pc -1) == '\t' || firstletter)
		{
			firstletter = 0;
			if(*pc >= '0' && *pc <= '9') //it's a number... push it on the stack
				{
				c = atof(pc);
				push(c);
				}
			else if(*pc == '+')
				a = pop(), b = pop(), push(a + b);
			else if(*pc == '-')
			{
				if(*(pc+1) >= '0' && *(pc+1) <= '9') //see if it's a negative number
				{
				c = atof(pc);
				push(c);
				}
				else //it's to subtract
					a = pop(), b = pop(), push(b - a);
			}
			else if(*pc == '*')
				a = pop(), b = pop(), push(a * b);
			else if(*pc == '/')
				a = pop(), b = pop(), push(b / a);
			else if(*pc == '%')
				a = pop(), b = pop(), push(fmod(b, a));
			else if(*pc == '^')
				a = pop(), b = pop(), push(pow(b, a));
			else if(*pc == 's')
				a = pop(), push(sin(a));
			else if(*pc == 'S')
				a = pop(), push(asin(a));
			else if(*pc == 'c')
				a = pop(), push(cos(a));
			else if(*pc == 'C')
				a = pop(), push(acos(a));
			else if(*pc == 't')
				a = pop(), push(tan(a));
			else if(*pc == 'T')
				a = pop(), push(atan(a));
			else if(*pc == 'l')
				a = pop(), push(log(a));
			else if(*pc == 'L')
				a = pop(), push(exp(a));
			else if(*pc == 'p')
				push(PI);
			else if(*pc == '#')
				printf("Top of stack: %f\n", *SP);
			else if(*pc == '@')
				printstack();
			else if(*pc == ']') //switch order
				a = pop(), b = pop(), push(a), push(b);
			else if(*pc == 'x')
				pop();
			else if(*pc == '!')
				a = pop(), push(factorial(a));
			else if(*pc == '\n' || *pc == ' ')
				;
			else
			{
				printf("Invalid character: '%c'\n", *pc);
				exit(1);
			}
			/* //uncomment this part in order to see view stack each time (or use @).
			if(!(*pc == '\n' || *pc == ' '))
				printstack();
			*/
		}
		pc++;
	}
	*result = *SP;
	
	SP = &STACK[0] - 1;  //reset stack
	
	return 1;
}


void printstack(void) //for testing or while using @
{
	double *pc;
	pc = SP;
	printf("\n");
	printf("---------\n");
	while(pc >= &STACK[0])
	{
		printf("%f\n", *pc);
		pc--;
	}
	printf("---------\n");
}

void push(double x) 
{
	if(SP >= &STACK[STACKSIZE-1])
	{
		printf("you have a stack overflow!\n");
		exit(-1);
	}
	++SP;
	*SP = x;
}

double pop(void)
{
	double tmp;
	
	if(SP < &STACK[0])
	{
		printf("you have a stack underflow!\n");
		exit(1);
	}
	
	tmp = *SP; //thing on top of stack
	SP--;
	return tmp;
}

int factorial(int n)
{
	int value;
	n = round(n);
	if(n <= 1)
	{
		value = 1;
	}
	else
	{
		value = n * factorial(n-1);
	}
	return value;
}

