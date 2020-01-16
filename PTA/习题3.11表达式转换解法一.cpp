#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool isOperator(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' 
		    || c == '(' || c == ')'); 
}

bool compareOperator(char a, char b)  //a为栈顶元素，与入栈元素b比较优先级
{                                     //返回true为优先级高，弹出 
	if (a == '(' || b == '(') {
		return false;
	}
	if (a == '*' || a == '/') {
		return true;
	}
	if (b == '*' || b == '/') {
		return false;
	}
	return true;
}

int main()
{
	freopen("E:in.txt", "r", stdin);
	char str[100];
	char stack[20];
	int top = -1, flag = 0, i = 0;
	gets(str);
	if (str[i]) {
		for (i = 0; str[i]; i++) {
			if (!isOperator(str[i]) ||
			    ((str[i] == '-' || str[i] == '+') && (i ? (isOperator(str[i - 1]) && str[i - 1] != ')') : 1))) {
			    	if (!isOperator(str[i]) || str[i] == '-') {
			    		printf("%c", str[i]);	
					}
			} else {
				if (str[i] != ')') {
					if (str[i] != '(') {
						printf(" ");
					}
					if (top == -1) {
						stack[++top] = str[i];
					} else {
						if (!compareOperator(stack[top], str[i])) {
							stack[++top] = str[i];
						} else {
							while (top != -1 && compareOperator(stack[top], str[i])) {
									printf("%c ", stack[top--]);
							}
							stack[++top] = str[i];
						}	
					} 
				} else {
					while (stack[top] != '(') {
						printf(" %c", stack[top--]);
					}
					top--;
				}
			}
		}
		while (top != -1) {
			printf(" %c", stack[top--]);
		}
	}
	
	fclose(stdin);
	return 0;
}
