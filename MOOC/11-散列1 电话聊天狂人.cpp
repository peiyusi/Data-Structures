#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define KEYLENGTH 13
#define MAXTABLESIZE 100001
typedef char ElementType[KEYLENGTH];
typedef int Index;

typedef struct LNode* PtrToLNode;
struct LNode{
	ElementType Data;
	int cnt;
	PtrToLNode Next;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode *HashTable;
struct TblNode {
	int TableSize;
	List Heads;
};

HashTable CreateTable( int TableSize );
Position Find( HashTable H, ElementType Key );
Index Hash( ElementType Key, int TableSize );
int NextPrime( int N );
void Insert( HashTable H, ElementType Key );
void ScanAndOutput( HashTable H );
void DestroyTable( HashTable H );



int main(){
	//freopen("C:\\in.txt","r", stdin);
	int N, i;
	scanf("%d", &N);
	HashTable H;
	ElementType Key;
	H = CreateTable( N*2 );
	for( i=0; i<N*2; i++){
		scanf("%s", Key);
		Insert( H, Key );
	}
	ScanAndOutput(H);
	DestroyTable( H );
	return 0;
}

void DestroyTable( HashTable H ){
	int i;
	Position P, Tmp;
	for( i=0; i<H->TableSize; i++ ){
		P = H->Heads[i].Next;
		while( P ){
			Tmp = P->Next;
			free( P );
			P = Tmp;
		}
	}
	free( H->Heads );
	free( H );
}

void ScanAndOutput( HashTable H ){
	int i;
	int N = 0;
	int max = 0;
	Position P;
	ElementType Key;
	for( i=0; i<H->TableSize; i++){
		P = H->Heads[i].Next;
		while( P ){
			if(max<P->cnt){
				max = P->cnt;
				strcpy(Key, P->Data);
				N = 1;
			}
			else if( max == P->cnt)
			{
				if(strcmp(Key, P->Data)>0)
					strcpy( Key, P->Data);
					N++;
				}
				P = P->Next;
		}
	}
	printf("%s %d", Key, max);
	if(N>1) printf(" %d", N);
	printf("\n");
}

HashTable CreateTable( int TableSize ) {
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);
	H->Heads = (List)malloc(H->TableSize*sizeof(struct LNode));
	for( i=0; i<H->TableSize; i++ ){
		H->Heads[i].Data[0] = '\0';
		H->Heads[i].Next = NULL;
		H->Heads[i].cnt = 0;
	}
	return H;
}

Index Hash( ElementType Key, int TableSize ){
	return atoi(Key+6) % TableSize;
}

int NextPrime( int N ){
	int i, p = ( N%2 )? N+2: N+1;
	while ( p<= MAXTABLESIZE ) {
		for( i = (int)sqrt(p); i>2; i-- )
			if( !(p%i) ) break;
		if( i==2 ) break;
		else p += 2;
	}
	return p;
}

Position Find( HashTable H, ElementType Key ){
	Position P;
	Index Pos;
	Pos = Hash(Key, H->TableSize);
	P = H->Heads[Pos].Next;
	while( P&& strcmp( P->Data, Key))
		P = P->Next;

	return P;
}

void Insert( HashTable H, ElementType Key ){
	Position P, NewCell;
	Index Pos;

	P = Find( H, Key );
	if( !P ){
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy( NewCell->Data, Key );
		Pos = Hash( Key, H->TableSize );
		NewCell->Next = H->Heads[Pos].Next;
		NewCell->cnt = 1;
		H->Heads[Pos].Next = NewCell;
	} else {
		P->cnt++;
	}
}
