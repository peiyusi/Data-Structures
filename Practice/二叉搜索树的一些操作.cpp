#include <stdio.h> 
#include <stdlib.h>

typedef int ElementType;
typedef struct Node *Position;
typedef Position BST;

struct Node {
    ElementType Data;
    Position Left;
    Position Right;
};

Position Find_Recursive(BST T, ElementType X)
{
	if (!T) {
		return NULL;
	}
	if (X < T->Data) {
		return Find_Recursive(T->Left, X);
	} else if (X > T->Data) {
		return Find_Recursive(T->Right, X);
	} else {
		return T;
	}
}

Position Find(BST T, ElementType X)
{
	while (T) {
		if (X < T->Data) {
			T = T->Left;
		} else if (X > T->Data) {
			T = T->Right;
		} else {
			break;
		}
	}
	
	return T;
}

BST Insert(BST T, ElementType X)
{
    if (!T) {
        T = (Position)malloc(sizeof(Node));
        T->Left = T->Right = NULL;
        T->Data = X;
    } else {
        if (X < T->Data) {
            T->Left = Insert(T->Left, X);
        } else if (X > T->Data) {
            T->Right = Insert(T->Right, X);
        } 
    }
    
    return T;
}

BST FindMax(BST T)
{
	if (T) {
		while (T->Right) {
	        T = T->Right;
	    }
	}
    
    return T;
}

BST FindMin_Recursive(BST T)
{
	if (T->Left) {
		return FindMin_Recursive(T->Left);
	} else {
		return T;
	}
}

void InOrder(BST T)
{
	static int flag = 0;
	if (T) {
		InOrder(T->Left);
		if (!flag) {
			printf("InOrder: %d", T->Data);	
			flag = 1;
		} else {
			printf(" %d", T->Data);	
		}
		InOrder(T->Right);
	}
}

BST Delete(BST T, ElementType X)
{
	if (!T) {
		return NULL;
	}
	BST prev = NULL;
	BST Head = T;
	while (T) {
		if (X < T->Data) {
			prev = T;
			T = T->Left;
		} else if (X > T->Data) {
			prev = T;
			T = T->Right;
		} else {
			break;
		}
	}
	if (!T) {
		return NULL;
	}
	if (T->Left && T->Right) {
		T = T->Left;
		BST temp = NULL;
		while (T->Right) {
			temp = T;
			T = T->Right;
		}
		if (prev) {
			if (prev->Left->Data == X) {
				prev->Left->Data = T->Data;
			} else {
				prev->Right->Data = T->Data;
			}
		} else {
			Head->Data = T->Data;
			Head->Left = T->Left; 
		}
		if (temp && T->Left) {
			temp->Right = T->Left;
		}	
	} else if (T->Left || T->Right) {
		if (T->Left) {
			if (prev) {
				if (prev->Left->Data == X) {
					prev->Left = T->Left;
				} else {
					prev->Right = T->Left;
				}					
			} else {
				Head->Data = T->Left->Data;
				Head->Left = T->Left->Left;
			}
		} else {
			if (prev) {
				if (prev->Left->Data == X) {
					prev->Left = T->Left;
				} else {
					prev->Right = T->Left;
				}				
			} else {
				Head->Data = T->Right->Data;
				Head->Right = T->Right->Right;
			}
		}
	} else {
		if (X < prev->Data) {
			prev->Left = NULL;
		} else {
			prev->Right = NULL;
		}
	} 
	
	return T;
}

BST Delete_Recursive(BST T, ElementType X)
{
	Position temp;
	if (T) {
		if (X < T->Data) {
			T->Left = Delete_Recursive(T->Left, X);
		} else if (X > T->Data) {
			T->Right = Delete_Recursive(T->Right, X);
		} else {
			if (T->Left && T->Right) {
				temp = FindMax(T->Left);
				T->Data = temp->Data;
				T->Left = Delete_Recursive(T->Left, temp->Data);
			} else {
				temp = T;
				if (!T->Left) {
					T = T->Right;
				} else {
					T = T->Left;
				}
				free(temp);
			}
		}
	} else {
		printf("É¾³ýÔªËØÎ´ÕÒµ½\n");
	}
	return T;
}

int main()
{
	freopen("E:in.txt", "r", stdin);
	BST Head, Max;
	Head = Max = NULL;
	int N, Data;
	scanf("%d", &N);
	while (N--) {
		scanf("%d", &Data);
		Head = Insert(Head, Data);
	}
	
	printf("%d\n", FindMin_Recursive(Head)->Data);
	InOrder(Head);

	fclose(stdin);
	return 0;
}



