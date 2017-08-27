bool Push( ElementType X, Deque D ) {
    bool flag = true;
    if (!D) {
    	flag = false;
	} else if (D->Rear == D->MaxSize) {
    	flag = false;
	} else {
		D->Data[D->Front] = X;
		D->Front++;
	}
	
	return flag;
}

ElementType Pop( Deque D ) {
	if (!D) {
		return false;
	} else if (D->Front == D->Rear) {
		return ERROR;
	} else {
		D->Front--;
		return D->Data[D->Front];
	}
}

bool Inject( ElementType X, Deque D ) {
	bool flag = true;
	if (!D) {
		flag = false;
	} else if (D->Rear == D->MaxSize) {
		flag = false;
	} else {
		D->Data[D->Front + D->Rear] = X;
		D->Rear++;
	}
	
	return flag;
}

ElementType Eject( Deque D ) {
	if (!D) {
		return false;
	} else if (D->Front == D->Rear) {
		return ERROR;
	} else {
		D->Rear--;
		return D->Data[D->Rear];
	}
}
