

ListNode* reverseList(ListNode* head) {
	if (head == NULL || head->next == NULL){
		return head;
	}
	ListNode* previous = head;
	ListNode* next = head->next;
	ListNode* nextnext = head->next->next;//maybe null  
	previous->next = NULL;
	while (next){
		nextnext = next->next;
		next->next = previous;
		previous = next;
		next = nextnext;

	}
	return previous;
}