#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef enum {left, right} Direction;
char stack[100];
int top = -1;

bool isEmpty()
{
	return (top == -1 ? true : false);
}

void Push(char x)
{
	stack[++top] = x;
}

void Pop()
{
	top--;
}

char getTop()
{
	return stack[top];
}

void Print(char c, Direction d)
{
	printf("NO\n");
	if (d == left) {
		if (c == '/') {
			printf("?-*/\n");
		} else {
			printf("?-%c\n", c);
		}		
	} else {
		if (c == '/') {
			printf("/*-?\n");
		} else {
			printf("%c-?\n", c);
		}
	}
	exit(0);
}

void Judge(char c) {
	if (isEmpty()) {
		Print(c, left);
	} else {
		if (c == '/') {
			if (getTop() == '/') {
				Pop();
			} else {
				Print(getTop(), right);
			}
		} else if (c == ')') {
			if (getTop() == '(') {
				Pop();
			} else {
				Print(getTop(), right);
			}
		} else if (c == ']') {
			if (getTop() == '[') {
				Pop();
			} else {
				Print(getTop(), right);
			}
		}  else if (c == '}') {
			if (getTop() == '{') {
				Pop();
			} else {
				Print(getTop(), right);
			}
		} 
	}
}


void Read(char str[]) {
	int i = 0;
	while (str[i]) {
		if (str[i] == '/' && str[i + 1] == '*') {    
			Push('/');
			i += 2;
		} else if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			Push(str[i++]);
		} else if (str[i] == '*' && str[i + 1] == '/') {
			Judge('/');
			i += 2;
		} else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			Judge(str[i++]);
		} else {
			i++;
		}
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	char str[100000];
	while (1) {
		gets(str);
		if (str[0] == '.' && str[1] == 0) {
			break;
		}
		Read(str); 
	}
	if (isEmpty()) {
		printf("YES\n");	
	} else {
		Print(getTop(), right);
	}
	
	//fclose(stdin);
	return 0;
}
