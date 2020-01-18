#include <stdio.h>
#include <stdlib.h>

typedef struct Node *ptrToNode;
struct Node {
	int data;
	ptrToNode left;
	ptrToNode right;
};

void Read(int a[], int n)
{
	int i;
	for (i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
}

ptrToNode CreateTree(int In[], int Post[], int l1, int r1, int l2, int r2)
{
	int i, llen, rlen;
	for (i = l1; i <= r1; i++) {
		if (In[i] == Post[r2]) break;
	}
	llen = i - l1;
	rlen = r1 - i;
	ptrToNode p = (ptrToNode)malloc(sizeof(struct Node));
	p->data = In[i];
	p->left = p->right = NULL;
	
	if (llen) {
		p->left = CreateTree(In, Post, l1, l1 + llen - 1, l2, l2 + llen - 1);
	}
	if (rlen) {
		p->right = CreateTree(In, Post, r1 - rlen + 1, r1, r2 - rlen, r2 - 1);
	}
	
	return p;
}

void preOrder(ptrToNode p) {
	static int flag = 0;
	if (p) {
		if (!flag) {
			flag = 1;
			printf("Preorder: %d", p->data);
		} else {
			printf(" %d", p->data);
		}
		preOrder(p->left);
		preOrder(p->right);
		free(p);
	}
}

int main()
{
//	freopen("E:in.txt", "r", stdin);
	int N;
	scanf("%d", &N);
	int Post[N], In[N];
	
	Read(Post, N);
	Read(In, N);
	preOrder(CreateTree(In, Post, 0, N - 1, 0, N - 1));
	
//	fclose(stdin);
	return 0;
}
