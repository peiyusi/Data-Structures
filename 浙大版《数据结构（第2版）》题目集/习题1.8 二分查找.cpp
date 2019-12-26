Position BinarySearch( List L, ElementType X )
{
	Position low = 1, high = L->Last;
	Position mid;
	while (low <= high) {
		mid = (low + high) / 2;
		if (L->Data[mid] == X) {
			return mid;
		} else if (L->Data[mid] < X) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
	return NotFound;
}
