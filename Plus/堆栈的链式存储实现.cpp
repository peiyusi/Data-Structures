//用C语言描述链栈如下
typedef struct SNode * PtrToSNode
struct SNode {
	ElementType Data;
	PtrToSNode Next;
};
typedef PtrToSNode Stack;

//带头节点的链栈主要操作的实现

//构建一个堆栈的头结点，返回该结点指针
Stack CreateStack() {
	Stack S;
	S = (Stack)malloc(sizeof(struct SNode));
	S->Next = NULL;
	return S;
}

//判断堆栈S是否为空，若是返回true，否则返回false
bool IsEmpty(Stack S) {
	return (S->Next == NULL);
}

//将元素X压入堆栈S
bool Push(Stack S, ElementType X) {
	PtrToSNode TmpCell;
	
	TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
	TmpCell->Data = X;
	TmpCell->Next = S->Next;
    S->Next = TmpCell;

    return true;	
}

//删除并返回堆栈S的栈顶元素
ElementType Pop(Stack S) {
	PtrToSNode FirstCell;
	ElementType TopElem;
	
	if (IsEmpty(S)) {
		printf("堆栈空\n");
		return ERROR;
	} else {
		FirstCell = S->Next;
		TopElem = FirstCell->Data;
		S->Next = FirstCell->Next;
		free(FirstCell);
		return TopElem;
	}
}
