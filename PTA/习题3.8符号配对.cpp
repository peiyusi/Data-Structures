TODO.. 


#include <stdio.h>

char stack[100];
int top = -1;

void Judge(char c)
{
	char t;
	switch(c) {
		case '/':
			stack[++top] = c;
			break;
		case '*':
			stack[++top] = c;
			break;
		case '(':
			stack[++top] = c;
			break;
		case '[':
			stack[++top] = c;
			break;
		case '{':
			stack[++top] = c;
			break;
		case ')':
			t = stack[top];
			if (t != '(') {
				printf("NO\n");
				printf("?-)\n");
				exit(0);
			} else {
				top--;
				break;
			}
		case ']':
			t = stack[top];
			if (t != '[') {
				printf("NO\n");
				printf("?-)\n");
				exit(0);
			}	
	}
}

int main()
{
	char c;
	while ((c = getchar()) != '.') {
		Judge(c);
	}
	int n = 1;
	while (n--) {
		printf("%d", n);
	}
	
	return 0;
}
