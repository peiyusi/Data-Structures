#include <stdio.h>
#include <stdlib.h>

typedef struct PolyNode *Poly;
struct PolyNode{
	int co;
	int exp; 
	Poly Next;
};

void Print(Poly p)
{
	int flag = 0;
	if (!p) {
		printf("0 0\n");
		return;
	}
	while (p) {
		if (!flag) {
			printf("%d %d", p->co, p->exp);		
			flag = 1;
		} else {
			printf(" %d %d", p->co, p->exp);
		}
		p = p->Next;
	}
	printf("\n");
}

void Attach(int co, int exp, Poly *rear)
{
	Poly p = (Poly)malloc(sizeof(struct PolyNode));
	p->co = co;
	p->exp = exp;
	p->Next = NULL;
	(*rear)->Next = p;
	*rear = p;
}

Poly FreeHead(Poly head) {
	Poly t = head;
	head = head->Next;
	free(t);
	
	return head;
}

Poly Read()
{
	int n, co, exp;
	Poly p, rear;
	p = (Poly)malloc(sizeof(struct PolyNode));
	p->Next = NULL;
	rear = p;
	scanf("%d", &n);
	while (n--) {
		scanf("%d %d", &co, &exp);
		Attach(co, exp, &rear);	
	}
	
	return FreeHead(p);
}

Poly Add(Poly p1, Poly p2)
{
	Poly p, rear;
	p = (Poly)malloc(sizeof(struct PolyNode));
	p->Next = NULL;
	rear = p;
	while (p1 && p2) {
		if (p1->exp == p2->exp) {
			if (p1->co + p2->co != 0) {
				Attach(p1->co + p2->co, p1->exp, &rear);	
			}
			p1 = p1->Next;
			p2 = p2->Next;
		} else if (p1->exp > p2->exp) {
			Attach(p1->co, p1->exp, &rear);
			p1 = p1->Next;
		} else {
			Attach(p2->co, p2->exp, &rear); 
			p2 = p2->Next;
		}
	}
	while (p1) Attach(p1->co, p1->exp, &rear), p1 = p1->Next;
	while (p2) Attach(p2->co, p2->exp, &rear), p2 = p2->Next;
	
	return FreeHead(p);
}

Poly Mult(Poly p1, Poly p2)
{
	Poly p = NULL, ptrp2, t, rear; 
	if (!p1 || !p2) {
		return NULL;
	}
	while (p1) {
		t = (Poly)malloc(sizeof(struct PolyNode));
		t->Next = NULL;
		rear = t;
		ptrp2 = p2;
		while (ptrp2) {
			Attach(p1->co * ptrp2->co, p1->exp + ptrp2->exp, &rear);
			ptrp2 = ptrp2->Next;
		}
		t = FreeHead(t);
		if (p == NULL) {
			p = Add(NULL, t);	
		} else {
			p = Add(p, t);	
		}
		p1 = p1->Next;
	}
	
	return p;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	Poly p1, p2, s, m;
	p1 = Read();
	p2 = Read();
	Print(Mult(p1, p2));
	Print(Add(p1, p2));

	//fclose(stdin);
	return 0;
}
