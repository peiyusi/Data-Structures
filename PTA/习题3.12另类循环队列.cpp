bool AddQ( Queue Q, ElementType X )
{
	if (Q->Count == Q->MaxSize) {
		printf("Queue Full\n");
		return false;
	}

	Q->Data[(Q->Front + Q->Count) % Q->MaxSize] = X;
    Q->Count++;	

	return true;
}

ElementType DeleteQ( Queue Q )
{
	if (Q->Count == 0) {
		printf("Queue Empty\n");
		return ERROR;
	}
	
    ElementType X = Q->Data[Q->Front];
    Q->Front = (Q->Front + 1) % Q->MaxSize;
	Q->Count--;
	
	return X;
}

 
