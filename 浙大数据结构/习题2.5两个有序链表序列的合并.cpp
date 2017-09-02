List Merge(List L1, List L2) {
	List temp1 = L1->Next;
	List temp2 = L2->Next;
	List p;
	p = (List)malloc(sizeof(List));
	List temp = p;
	while (temp1 && temp2) {
		if (temp1->Data < temp2->Data) {
			temp->Next = temp1;
			temp1 = temp1->Next;
			temp = temp->Next;
		} else {
			temp->Next = temp2;
			temp2 = temp2->Next;
			temp = temp->Next;
		} 
	}
	while (temp1 != NULL) {
		temp->Next = temp1;
		temp1 = temp1->Next;
		temp = temp->Next;
	}
	while (temp2 != NULL) {
		temp->Next = temp2;
		temp2 = temp2->Next;
		temp = temp->Next;
	}
	L1->Next = NULL;
	L2->Next = NULL;
	temp->Next = NULL;
	
	return p;
}
