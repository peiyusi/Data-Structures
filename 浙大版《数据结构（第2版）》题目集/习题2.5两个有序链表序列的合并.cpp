List Merge(List L1, List L2) {
	List L = (List)malloc(sizeof(struct Node));
	L->Next = NULL;
	PtrToNode p1 = L1->Next, p2 = L2->Next, p = L;
	
	while (p1 && p2) {
		if (p1->Data < p2->Data) {
			p->Next = p1;
			p1 = p1->Next;
		} else {
			p->Next = p2;
			p2 = p2->Next;
		}
		p = p->Next;
	}
	
    if (p1) {
    	p->Next = p1;
	} else if (p2) {
		p->Next = p2;
	} else {
		p->Next = NULL;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	
	return L;
}
