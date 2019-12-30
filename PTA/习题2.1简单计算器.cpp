#include <stdio.h>
#include <stdlib.h> 

void error()
{
    printf("ERROR");
    exit(0);
}

void getResult()
{
	char c;
	int result, x;

	if ((scanf("%d", &result)) != 1) {
        error();
    }
	while ((c = getchar()) != '=')
	{
		if ((scanf("%d", &result)) != 1) {
            error();
        }
		switch(c) {
			case '+':
				result += x;
				break;
			case '-':
				c++;
				result -= x;
				break;
			case '*':
				c++;
				result *= x;
				break;
			case '/':
				if (x == 0) {
					error();
				} else {
					result /= x;
					break;
				}
            default:
                error();	
		}
	}
	
	printf("%d", result);
}

int main()
{
	getResult();
		
	return 0;
}
