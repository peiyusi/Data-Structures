#include <stdio.h>
#include <stdlib.h>

typedef struct AVLNode *AVLTree;
struct AVLNode {
	int Data;
	int Height;
	AVLTree Left;
	AVLTree Right;
};

int Max(int A, int B)
{
	return A > B ? A : B;
}

int GetHeight(AVLTree T)
{
//    if (T) {
//    	int L = GetHeight(T->Left);
//    	int R = GetHeight(T->Right);
//        return (L > R ? L : R) + 1;
//    }
//	return 0;
	return T ? T->Height : 0;
}

void UpdateHeight(AVLTree T)
{
	T->Height = Max(GetHeight(T->Left), GetHeight(T->Right)) + 1;
}

int GetBF(AVLTree T)
{
	return GetHeight(T->Left) - GetHeight(T->Right);
}

AVLTree LeftRotation(AVLTree A)
{
	AVLTree B = A->Left;
	A->Left = B->Right;
	B->Right = A;
	
	UpdateHeight(A);
	UpdateHeight(B);
	
	return B;
}

AVLTree RightRotation(AVLTree A)
{
	AVLTree B = A->Right;
	A->Right = B->Left;
	B->Left = A;
	
	UpdateHeight(A);
	UpdateHeight(B);
	
	return B;
}

AVLTree LeftAndRightRotation(AVLTree A)
{
	A->Left = RightRotation(A->Left);;
	return LeftRotation(A);
}

AVLTree RightAndLeftRotation(AVLTree A)
{
	A->Right = LeftRotation(A->Right);
	return RightRotation(A);
}

AVLTree Insert(AVLTree T, int X)
{
	if (!T) {
		T = (AVLTree)malloc(sizeof(struct AVLNode));
		T->Data = X;
		T->Height = 1;
		T->Left = T->Right = NULL;
	} else {
		if (T->Data < X) {
			T->Right = Insert(T->Right, X);
			if (GetBF(T) == -2) {
				if (T->Right->Data < X) {
					T = RightRotation(T);
				} else {
					T = RightAndLeftRotation(T);
				}
			}
		} else if (T->Data > X) {
			T->Left = Insert(T->Left, X);
			if (GetBF(T) == 2) {
				if (T->Left->Data > X) {
					T = LeftRotation(T);
				} else {
					T = LeftAndRightRotation(T);
				}
			}
		}
		UpdateHeight(T);
	}
	
	return T;
}

int main()
{
	//freopen("E:in.txt", "r", stdin);
	int N, X;
	AVLTree Head = NULL;
	scanf("%d", &N);
	while (N) {
		scanf("%d", &X);
		Head = Insert(Head, X);
		N--; 
	}
	printf("%d", Head->Data);
	
	//fclose(stdin);
	return 0;
}
