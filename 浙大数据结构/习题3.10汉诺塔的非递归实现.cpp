#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
typedef struct Problem{
    int n;
    char src,mid,dest;
    struct Problem *Next;
}Stack;

Stack *CreateStack()
{
    Stack *S;
    S=(Stack*)malloc(sizeof(struct Problem));
    S->Next=NULL;
    return S;
}

bool IsEmpty(Stack *S)
{
    return (S->Next==NULL);
}

void Push(Stack *S,int n,char A,char B,char C)
{
    Stack *TmpCell;
    TmpCell=(Stack *)malloc(sizeof(struct Problem));
    TmpCell->n=n;
    TmpCell->src=A;
    TmpCell->mid=B;
    TmpCell->dest=C;
    TmpCell->Next=S->Next;
    S->Next=TmpCell;
}

Stack *Pop(Stack *S,Stack *curPrb)
{
    Stack *FirstCell;
    FirstCell=(Stack *)malloc(sizeof(struct Problem));
    FirstCell=S->Next;
    curPrb->n=FirstCell->n;curPrb->src=FirstCell->src;curPrb->mid=FirstCell->mid;curPrb->dest=FirstCell->dest;
    S->Next=FirstCell->Next;
    free(FirstCell);
    return curPrb;
}

int main()
{
    int n;
    scanf("%d",&n);
    Stack *S;
    S=CreateStack();
    Push(S,n,'a','b','c');
    while (!IsEmpty(S))
    {
        Stack *curPrb;
        curPrb=(Stack *)malloc(sizeof(struct Problem));
        curPrb=Pop(S,curPrb);
        if (curPrb->n==1)printf("%c -> %c\n",curPrb->src,curPrb->dest);
        else
        {
            Push(S,curPrb->n-1,curPrb->mid,curPrb->src,curPrb->dest);//堆栈的顺序和递归正好相反
            Push(S,1,curPrb->src,curPrb->mid,curPrb->dest);
            Push(S,curPrb->n-1,curPrb->src,curPrb->dest,curPrb->mid);
        }
        free(curPrb);
    }
    free(S);
    return 0;
}
