bool IsBST ( BinTree T )
{
    static ElementType prev = -32768;
    bool l, r;
	if (T == NULL) {
		return true;
	}
    l = IsBST(T->Left);
    if (!l || T->Data < prev) {
        return false;
    }
    prev = T->Data;
    r = IsBST(T->Right);
    return r;
}
