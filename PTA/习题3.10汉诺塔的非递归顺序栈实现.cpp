#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct FuncNode *Node;
struct FuncNode {
	char a, b, c;
	int n;
};

typedef struct StackNode *Stack;
struct StackNode {
	Node *Data;
	int top;
	int maxSize;
};

Node initNode(char a, char b, char c, int n)
{ 
	Node node = (Node)malloc(sizeof(struct FuncNode));
	node->a = a, node->b = b, node->c = c, node->n = n;
	
	return node; 
}

Stack initStack()
{
	Stack stack = (Stack)malloc(sizeof(struct StackNode));
	stack->maxSize = 100;
	stack->Data = (Node *)malloc(stack->maxSize * sizeof(Node));
	stack->top = -1;
	
	return stack;
}

bool isEmpty(Stack stack)
{
	return stack->top == -1;
}

bool isFull(Stack stack)
{
	return stack->top == stack->maxSize - 1;
}

void Push(Stack s, char a, char b, char c, int n)
{
	if (!isFull(s)) {
		s->Data[++s->top] = initNode(a, b, c, n);
	}
}

Node Pop(Stack s)
{
	if (!isEmpty(s)) {
		return s->Data[s->top--];
	}
}

int main()
{
	Stack stack;
	Node n;
	int N;
	scanf("%d", &N);
		
	if (N > 0) {
		stack = initStack();
		Push(stack, 'a', 'b', 'c', N);
		while (!isEmpty(stack)) {
			n = Pop(stack);
			if (n->n == 1) {
				printf("%c -> %c\n", n->a, n->c);
			} else if (n->n > 0){
				Push(stack, n->b, n->a, n->c, n->n - 1);        //入栈顺序和递归时的顺序相反 
				Push(stack, n->a, n->b, n->c, 1);
				Push(stack, n->a, n->c, n->b, n->n - 1);
			}
			free(n);
		}
	}
	
	return 0;
}
