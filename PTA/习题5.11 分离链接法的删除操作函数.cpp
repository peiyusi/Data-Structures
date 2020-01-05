bool Delete( HashTable H, ElementType Key )
{
	Index HashKey = Hash(Key, H->TableSize);
	PtrToLNode p = &(H->Heads[HashKey]), t;
	while (p->Next) {
		if (!strcmp(p->Next->Data, Key)) {
            t = p->Next;
            p->Next = t->Next;
            free(t);
			printf("%s is deleted from list Heads[%d]", Key, HashKey);
			return true;
		}
		p = p->Next;
	}
	
	return false;
}

//提供了string.h， 可以直接使用strcmp， 也可以自己写一个 
//int mystrcmp(const char *s1, const char *s2)
//{
//    int ret = 0;
//    while (!(ret = *(unsigned char *)s1 - *(unsigned char *)s2) && *s1) {
//        s1++;
//        s2++;
//    }
//    if (ret > 0) {
//        ret = 1;
//    } else if (ret < 0) {
//        ret = -1;
//    }
// 
//    return ret;
//}
