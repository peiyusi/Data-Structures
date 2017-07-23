List Insert( List L, ElementType X) {
	List pt1, pt2, pt;
	if (L->Next == NULL) {
		pt = (List)malloc(sizeof(List));
		pt->Data = X;
		pt->Next = NULL;
		L->Next = pt;
		return L;
	}
	pt1 = L;
	pt2 = L->Next;
	while (pt2 != NULL && X >= pt2->Data) {
		pt1 = pt2;
		pt2 = pt2->Next;
	}
	
	pt = (List)malloc(sizeof(List));
	pt->Data = X;
	pt->Next = pt2;
	pt1->Next = pt;
	
	return L;
}
