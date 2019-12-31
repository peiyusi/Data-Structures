bool isFull(Deque D)
{
    return ((D->Rear + 1) % D->MaxSize == D->Front ? true : false);
}

bool isEmpty(Deque D)
{
    return (D->Front == D->Rear ? true : false);
}

bool Push( ElementType X, Deque D )
{
    if (isFull(D)) {
        return false;
    }

    D->Front = (D->Front - 1 + D->MaxSize) % D->MaxSize;
    D->Data[D->Front] = X;
    
    return true;
}

ElementType Pop( Deque D )
{
    if (isEmpty(D)) {
        return ERROR;
    }

    ElementType X = D->Data[D->Front];
    D->Front = (D->Front + 1) % D->MaxSize;

    return X;
}

bool Inject( ElementType X, Deque D )
{
    if (isFull(D)) {
        return false;
    }

    D->Data[D->Rear] = X;
    D->Rear = (D->Rear + 1) % D->MaxSize;

    return true;
}
ElementType Eject( Deque D )
{
    if (isEmpty(D)) {
        return ERROR;
    }

    D->Rear = (D->Rear - 1 + D->MaxSize ) % D->MaxSize;
    ElementType X = D->Data[D->Rear];
    
    return X;
}
