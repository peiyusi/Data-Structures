ElementType Find( List L, int m ) {
	List former, latter;
	int instance = 0;
	int i;
	
	if (L->Next == NULL) {
		return ERROR;
	} else {
		former = L->Next;
		latter = L->Next;
		while (former) {
			former = former->Next;
			instance++;
		}
		if (m > instance) {
			return ERROR;
		} else if (m == instance) {
			return latter->Data;
		} else {
			for (i = 0; i < instance - m; i++) {
				latter = latter->Next;
			}
			return latter->Data;
		}
	}
	
} 
