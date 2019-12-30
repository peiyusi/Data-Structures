bool IsBST ( BinTree T ) {
  static BinTree prev = NULL;
  if (T) {
    if (!IsBST(T->Left)) {
		return false;
	}
    if (prev != NULL && T->Data <= prev->Data) {
		return false;
	}    
    prev = T;    
    return IsBST(T->Right);
  }
  return true;
}