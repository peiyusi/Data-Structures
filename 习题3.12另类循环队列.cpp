bool AddQ( Queue Q, ElementType X ) {
	Queue q;
	q = Q;
	if (q->Count == q->MaxSize) {
		printf("Queue Full\n");
		return false;
	} else {
		q->Count++;
		q->Data[q->Front + q->Count] = X;
	}
}

ElementType DeleteQ( Queue Q ) {
	int i;
	ElementType temp;
	Queue q;
	q = Q;
	if (q->Count == 0) {
		printf("Queue Empty\n");
		return ERROR;
	} else {
		q->Count--;
		q->Front++;
		return q->Data[q->Front];
	}
}


