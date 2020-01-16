#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


typedef struct Node *ptrToNode;
struct Node {
	char a, b, c;
	int n;
	ptrToNode next;
};
typedef ptrToNode Stack;

ptrToNode initPtrToNode(char a, char b, char c, int n)
{ 
	ptrToNode node = (ptrToNode)malloc(sizeof(struct Node));
	node->a = a, node->b = b, node->c = c, node->n = n, node->next = NULL;
	
	return node; 
}

Stack initStack()
{
	Stack stack = (Stack)malloc(sizeof(struct Node));
	stack->next = NULL;
	
	return stack;
}

bool isEmpty(Stack stack)
{
	return stack->next == NULL;
}

void Push(Stack s, char a, char b, char c, int n)
{
	ptrToNode node = initPtrToNode(a, b, c, n);
	node->next = s->next;
	s->next = node;
}

ptrToNode Pop(Stack s)
{
	ptrToNode t = NULL;
	if (s->next) {
		t = s->next;
		s->next = t->next;
	}
	
	return t;
}

int main()
{
	Stack stack;
	ptrToNode n;
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
