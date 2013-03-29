/************
Linked List
**************/
/*
Find m to last in linked list
*/
element *FindMtoLast(element *head, int m)
{
  element	*current,*mbehind;
	current = head;
	
	for(int i=0;i<m-1,i++){
		current = current->next;
	}
	
	if(!current) return NULL;
	
	mbehind = head;
	while(current->next){
		current = current->next;
		mbehind = mbehind->next;
	}
	
	return mbehind;
}

/*
Find whether there is circle in linked list
*/

/*
Reverse link list
*/
//method 1: Non recursive:
Node* Reverselinkedlist (Node *ptr)
{
	Node *temp;
	Node *previous = NULL;
	while(ptr){
		temp = ptr->next;
		ptr->next = previous;
		previous = ptr;	
		ptr = temp;		
	}
	
	return previous;
}

//method 2: recursive:
Node * reverse( Node * ptr , Node * previous)
{
    Node * temp;
    if(ptr->next == NULL) {
        ptr->next = previous;
        return ptr;
    } else {
        temp = reverse(ptr->next, ptr);
        ptr->next = previous;
        return temp;
    }
}
reversedHead = reverse(head, NULL);

//recursive:
void reverse(Node*& p) {
    if (!p) return;
    Node* rest = p->next;
    if (!rest) return;
    reverse(rest);
    p->next->next = p;
    p->next = NULL;
    p = rest;
}
/************************************************************
 Reverse a linked list from position m to n. Do it in-place and in one-pass.

For example:
Given 1->2->3->4->5->NULL, m = 2 and n = 4,

return 1->4->3->2->5->NULL. 
*************************************************************/
ListNode *reverseBetween(ListNode* head, int m, int n){
    // Start typing your C/C++ solution below
    // DO NOT write int main() function
    int i=1;
    int j=1;
    ListNode *start= head;
    ListNode *end = head;
    ListNode *tmp1= NULL;
    ListNode *tmp2= NULL;
    
	while(i<m){
        tmp1 = start;
        start = start->next;
        end = end->next;
        i++;
        j++;
    }
    tmp2 = start;
        
    while(j<n){
        tmp2 = start->next;
        start->next = tmp2->next;
        tmp2->next = end;
		end = tmp2;
        j++;
    }
    
	if(!tmp1){
		head->next = start->next;
		head = tmp2;
	}else{
		tmp1->next = end;
	}
        
    return head;
}

/************************************************************
Swap Nodes in Pairs: leetcode

For example:
Given 1->2->3->4->5->NULL,

return 2->1->4->3->5->NULL. 
*************************************************************/
ListNode *swapPairs(ListNode *head) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	ListNode *nextone;
	ListNode *curr;
	ListNode *tmphead;
	ListNode *returnhead;
	
	if(head == NULL || head->next == NULL)
		return head;
	
	nextone = head->next;
	curr = head;
	tmphead = curr;
	returnhead = head->next;
	
	while(curr!=NULL && curr->next != NULL){
		nextone = curr->next;
		tmphead->next = nextone;
		tmphead = curr;
		curr->next = nextone->next;
		nextone->next = curr;
		curr = tmphead->next;
		
		
	}
	
	return returnhead;
	
}

//This kind of questions can be done using recursive also
ListNode *swapPairs(ListNode *head) {
	if(head == NULL || head->next == NULL) return head;
	ListNode * curr = head;
	ListNode * tmp = NULL;
	if(curr->next && curr->next->next){
		tmp = swapPairs(head->next->next);
	}
	ListNode * nextone = curr->next;
	curr->next = tmp;
	nextone->next = curr;
	return nextone;
}

//More on this: reverse at every N node,Reverse Nodes in k-Group
//1->2->3->4->5->6:  reverse every 3, 3->2->1->6->5->4
/*
 For example,
Given this linked list: 1->2->3->4->5

For k = 2, you should return: 2->1->4->3->5

For k = 3, you should return: 3->2->1->4->5 
*/
ListNode *reverseKGroup(ListNode *head, int k) {
   if(!head) return NULL;
	ListNode* cur = head;
	int i = 0;
	while(cur)
	{
		i++;
		if(i>=k) break;
		cur = cur->next;
	}
	if(i<k)
		return head;
   
	ListNode* pre = NULL;
	ListNode* next;
	cur = head;
	i = k;
	while(cur && i>0)
	{
	   next = cur->next;
	   cur->next = pre;
	   pre = cur;
	   cur = next; 
	   i--;
	}
   
	head->next = reverseKGroup(cur, k);
	//pre is the return 
	return pre;
		
	
}




//merge two sorted list
/*
Merge two sorted linked lists and return it as a new list. 
The new list should be made by splicing together the nodes of the first two lists.
*/
ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	if(!l1) return l2;
	if(!l2) return l1;
	ListNode *head;
	ListNode *tmp;
	
	if(l1->val>l2->val){
		head = l2;
		l2 = l2->next;
	}else{
		head = l1;
		l1 = l1->next;
	}
	tmp = head;
	
	while(1){
		
		if(!l2) {
			tmp->next = l1;
			break;
		}
		if(!l1) {
			tmp->next = l2;
			break;
		}
		
		if(l1->val>l2->val){
			tmp->next = l2;
			tmp=l2;
			l2 = l2->next;
		}else{
			tmp->next = l1;
			tmp = l1;
			l1 = l1->next;
		}
	}
	
	return head;
}
