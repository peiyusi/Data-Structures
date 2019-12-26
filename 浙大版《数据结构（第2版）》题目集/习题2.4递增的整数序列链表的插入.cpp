List Insert( List L, ElementType X) {
	PtrToNode p = L;
	PtrToNode n = (PtrToNode)malloc(sizeof(struct Node));  
	n->Data = X;
	while (p->Next && p->Next->Data < X) p = p->Next;
	n->Next = p->Next;
	p->Next = n;
	
	return L;
}
