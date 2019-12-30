ElementType Find( List L, int m )
{
	int i = 0;
	PtrToNode p1, p2;
	p1 = p2 = L->Next;
	while(i++ < m) {
		if (p1 == NULL) {
			return ERROR;
		}
		p1 = p1->Next;
	}
	while(p1 != NULL) {
		p1 = p1->Next;
		p2 = p2->Next;
	}
	
	return p2->Data; 	
}
