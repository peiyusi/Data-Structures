#include <stdio.h>
#include <stdlib.h>
typedef struct AVLNode *Position;
typedef Position AVLTree;
struct AVLNode { 
	int Data;
	AVLTree Left;
	AVLTree Right;
	int Height;
};

int Max(int x1, int x2) {
	return x1 > x2 ? x1 : x2;
}

int Height(Position a) {
	if (a == NULL) {
		return -1;
	}
	return a->Height;
}

Position SingleRotateWithLeft(Position a) {
    Position b = a->Left;
    a->Left = b->Right;
    b->Right = a;
    a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
    b->Height = Max(Height(b->Left), Height(b->Right)) + 1;
    return b;      
}

Position SingleRotateWithRight(Position b) {
    Position a = b->Right;
    b->Right = a->Left;
    a->Left = b;
    a->Height = Max(Height(a->Left), Height(a->Right)) + 1;
    b->Height = Max(Height(b->Left), Height(b->Right)) + 1;
    return a;       
}

Position DoubleRotateWithLeft(Position a) {
	a->Left = SingleRotateWithRight(a->Left);
	return SingleRotateWithLeft(a);
}

Position DoubleRotateWithRight(Position a) {
	a->Right = SingleRotateWithLeft(a->Right);
	return SingleRotateWithRight(a);	
}

AVLTree Insert(int x, AVLTree T) {
	if (!T) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = x;
		T->Left = T->Right = NULL;
		T->Height = 0;
	} else if (x < T->Data) {
		T->Left = Insert(x, T->Left);
		if (Height(T->Left) - Height(T->Right) == 2) {
            if (x < T->Left->Data) {
                T = SingleRotateWithLeft(T);
            } else {
                T = DoubleRotateWithLeft(T);
            }
        }
	} else if (x > T->Data) {
		T->Right = Insert(x, T->Right);
		if (Height(T->Right) - Height(T->Left) == 2) {
			if (x > T->Right->Data) {
				T = SingleRotateWithRight(T);
			} else {
				T = DoubleRotateWithRight(T);
			}
		}
	}
	T->Height = Max(Height(T->Left), Height(T->Right)) + 1;
	return T;
}

int main() {
	int N, key, i;
	AVLTree T = NULL;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d", &key);
		T = Insert(key, T);
	}
	printf("%d\n", T->Data);
	
	return 0;
}
