bool Push( ElementType X, Deque D ) {
    bool flag = true;
    if (D->Front == (D->Rear + 1) % D->MaxSize) {
    	flag = false;
	} else {
		D->Front = (D->Front + D->MaxSize - 1) % D->MaxSize;
		D->Data[D->Front] = X;
	}
	
	return flag;
}

ElementType Pop( Deque D ) {
	ElementType temp;
	if (D->Front == D->Rear) {
		return ERROR;
	} else {
		temp =  D->Data[D->Front];
		D->Front = (D->Front + 1) % D->MaxSize;
		return temp;
	}
}

bool Inject( ElementType X, Deque D ) {
	bool flag = true;
	if (D->Front == (D->Rear + 1) % D->MaxSize) {
		flag = false;
	} else {
		D->Data[D->Rear] = X;
		D->Rear = (D->Rear + 1) % D->MaxSize;
	}
	
	return flag;
}

ElementType Eject( Deque D ) {
	if (D->Front == D->Rear) {
		return ERROR;
	} else {
	    D->Rear = (D->Rear + D->MaxSize - 1) % D->MaxSize;
	    return D->Data[D->Rear];
	}
}
