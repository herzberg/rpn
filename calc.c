//Josh Herzberg
//See: https://en.wikipedia.org/wiki/Reverse_Polish_notation
#include <stdio.h>
#include <stdlib.h>
#include "rpneval.h"



main()
{
	char *pc;
	char buf[256];
	double result;
	
	while(1)
	{
		printf("Enter Expression. Example: 2 3 4 + *(= (3+4)*2). ctrl + C to exit:\n");
		fgets(buf, 256, stdin);
		eval_rpn(&result, buf);
		printf("result = %f\n", result);
	}

}

