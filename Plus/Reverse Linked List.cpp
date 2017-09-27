public ListNode reverseList(ListNode head) {
    ListNode current = head->Next;
	ListNode prev = NULL;
	ListNode temp;
	while (current != NULL) {
		temp = current->Next;
		current->Next = prev;
		prev = current;
		current = temp;
	}
	head->Next->Next = prev;
	
	return head;
}