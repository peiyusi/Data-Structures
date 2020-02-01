#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define PERCENT 10
#define MAXTABLESIZE 200
#define TABLESIZE 100
#define WORDLEN 15

typedef char *ElementType;

typedef struct LNode *PtrToLNode;
struct LNode {
	ElementType Data;
	int Count;
	PtrToLNode Next;
};
typedef PtrToLNode Position;

struct HNode {
	PtrToLNode *Head;
	int Size;
}; 
typedef struct HNode *HashTable;

int NextPrime(int N)
{
	int i, P;
	
	P = (N % 2) ? N + 2 : N + 1;
	while (P <= MAXTABLESIZE) {
		for (i = (int)sqrt(P); i > 2; i--) {
			if (!P % i) {
				break;
			} 
		}
		if (i == 2) {
			break;
		} else {
			P += 2;
		}
	}
	
	return P;
} 

int Hash(const char *Key, int TableSize)
{
	unsigned int H;
	
	H = 0;
	while (*Key) {
		H = (H << 5) + *Key++;
	}
	
	return H % TableSize;
}

char toLowerCase(char c) {
	return c + ('a' - 'A');
}

bool isWordCharacter(char c)
{
	return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') 
			|| (c >= '0' && c <= '9') || (c == '_');
}

bool isUpper(char c) {
	return c >= 'A' && c <= 'Z';
}

bool getWord(ElementType str, ElementType word, int *start)
{
	int i, len;
	bool flag;
	char c;
	
	flag = true;
	i = *start, len = 0;
	while (str[i]) {
		c = str[i++];
		if (isWordCharacter(c)) {
			if (len != WORDLEN) {
				if (isUpper(c)) {
					c = toLowerCase(c);
				}
				word[len++] = c;
			} else {
				continue;
			}	
		} else {
			if (c == '#') {
				flag = false;
				break;
			}
			if (len) {
				break;
			} 
		}
	}
	
	*start = i;
	word[len] = '\0';
	
	return flag;
}

bool Compare(ElementType A, ElementType B)
{	
	while (*A && *B && (*A == *B)) {
		A++, B++;
	}
	if (*A && *B) {
		return (*B - *A) > 0 ? true : false;
	} 
	return *A ? false : true;
} 

HashTable CreateTable()
{
	HashTable H;
	int i;
	
	H = (HashTable)malloc(sizeof(struct HNode));
	H->Size = NextPrime(TABLESIZE);
	H->Head = (PtrToLNode *)malloc(sizeof(PtrToLNode) * (H->Size + 1));
	for (i = 0; i <= H->Size; i++) {
		H->Head[i] = (PtrToLNode)malloc(sizeof(struct LNode));
		H->Head[i]->Count = 0;
		H->Head[i]->Data = NULL;
		H->Head[i]->Next = NULL;
	}
	
	return H;
}

Position Find(HashTable H, ElementType Key)
{
	Position P;
	int Index;
	
	Index = Hash(Key, H->Size);
	P = H->Head[Index]->Next;
	while (P && strcmp(Key, P->Data)) {
		P = P->Next;
	}
	
	return P;
}

void Insert(HashTable H, ElementType Key)
{
	Position P;
	PtrToLNode NewCell;
	int Index;
	
	P = Find(H, Key);
	if (!P) {
		Index = Hash(Key, H->Size);
		NewCell = (PtrToLNode)malloc(sizeof(struct LNode));
		NewCell->Count = 1;
		NewCell->Data = (ElementType)malloc((strlen(Key) + 1) * sizeof(char));
		strcpy(NewCell->Data, Key);
		NewCell->Next = H->Head[Index]->Next;
		H->Head[Index]->Next = NewCell;
		H->Head[H->Size]->Count++;
	} else {
		P->Count++;
	}
}

void DestroyTable(PtrToLNode Head) {
	PtrToLNode Temp;
	while (Head) {
		Temp = Head->Next;
		free(Head);
		Head = Temp;
	}
}

void Print(HashTable H)
{
	Position P1, P2;
	PtrToLNode Head, Temp;
	int i, Size;
	
	Size = H->Head[H->Size]->Count / PERCENT;
	Head = (PtrToLNode)malloc(sizeof(struct LNode));
	Head->Next = NULL;
	for (i = 0; i < H->Size; i++) {
		P1 = H->Head[i]->Next;
		while (P1) {
			P2 = Head;
			Temp = P1->Next;
			while (P2->Next && P1->Count < P2->Next->Count) {
				P2 = P2->Next;
			}
			if (!P2->Next) {
				P2->Next = P1;
				P1->Next = NULL;
			} else {
				while (P2->Next && P1->Count == P2->Next->Count && !Compare(P1->Data, P2->Next->Data)) {
					P2 = P2->Next;
				}
				P1->Next = P2->Next;
				P2->Next = P1;
			}
			P1 = Temp;
		}	
	}
	
	printf("%d\n", H->Head[H->Size]->Count);
	P2 = Head->Next;
	while (Size-- && P2) {
		printf("%d:%s\n", P2->Count, P2->Data);
		P2 = P2->Next;	
	}
	
	DestroyTable(Head);	
}

int main() 
{
	//freopen("E:in.txt", "r", stdin);
	char str[1000], Word[16];
	bool flag;
	int i;
	HashTable H;
	
	flag = true;
	H = CreateTable();
	while (flag) {
		i = 0;
		if (scanf("%s", str) != EOF) {
			while (str[i] && flag) {
				flag = getWord(str, Word, &i);
				if (Word[0]) {
					Insert(H, Word);
				}
			}	
		}	
	}
	
	Print(H);
	
    //fclose(stdin);
    return 0;
}
 

