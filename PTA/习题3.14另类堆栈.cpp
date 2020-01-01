bool Push( Stack S, ElementType X )
{
	if (S->Top == S->MaxSize) {
		printf("Stack Full\n");
		return false;
	}

	S->Data[S->Top] = X;
	S->Top++;
	
	return true;
}

ElementType Pop( Stack S )
{
	if (S->Top == 0) {
		printf("Stack Empty\n");
		return ERROR;
	}
	
	S->Top--;
	
	return S->Data[S->Top];
}
