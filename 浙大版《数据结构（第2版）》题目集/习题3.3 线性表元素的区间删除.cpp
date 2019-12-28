List Delete( List L, ElementType minD, ElementType maxD )
{
	Position i, j;
    i = j = 0;
    while (i <= L->Last) {
        if (L->Data[i] <= minD || L->Data[i] >= maxD) {
			L->Data[j++] = L->Data[i];
		}
        i++;
    }
	L->Last = j - 1;

	return L;
}

List Delete( List L, ElementType minD, ElementType maxD )
{
	Position i, j;
    i = j = 0;
    while (i <= L->Last) {
        if (L->Data[i] > minD && L->Data[i] < maxD) {
			j++;
		} else {
            L->Data[i - j] = L->Data[i];
        }
        i++;
    }
	L->Last = i - j - 1;

	return L;
}  
 
