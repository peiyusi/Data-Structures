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

//recursive
//Position BinarySearchRecursive( List L, ElementType X, Position left, Position right )
//{
//	if (left > right) {
//		return NotFound;
//	}
//	Position mid = (left + right) / 2;
//	ElementType midData = L->Data[mid];
//	if (midData == X) {
//		return mid; 
//	} else if (midData > X) {
//		return BinarySearchRecursive(L, X, left, mid - 1);
//	} else {
//		return BinarySearchRecursive(L, X, mid + 1, right);
//	}
//}
//
//Position BinarySearch( List L, ElementType X )
//{
//	return BinarySearchRecursive(L, X, 1, L->Last);
//}


