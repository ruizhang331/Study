/**
Implemention of atoi and itoa
**/

//INT_MIN = -2147483648

int atoi(const char* str)
{
    if ((str == NULL) || (*str == '\0'))
        return 0;
    bool sign = false;
    while (*str == ' ')
        str ++;
    if (*str == '-')
    {   
        sign = true;
        str ++;
    }
    else if (*str == '+')
        str ++;
    long long val = 0;
    while ((*str >= '0') && (*str <= '9'))
    {
        val = val*10 + (*str - '0');
        long long tmp = val;
        if (sign == true)
            tmp = -val;
        if (tmp >= INT_MAX)
            return INT_MAX;
        else if (tmp <= INT_MIN)
            return INT_MIN;

        str ++;
    }
    if (sign == true)
        return -val;
    else
        return val;
};

char* itoa(int value){
  char *pStr = NULL;
	int length = 0;
	bool negative = false;
	
	if(value<0){
		length++;
		value = -value;
		negative = true;
	}
	int temp = value;
	do{
		temp=temp/10;
		length++;
	}while(temp>0)
	
	pStr = (char *)malloc(sizeof(char)*(length+1));
	for(int i=0;i<length;i++){
		pStr[length-i-1]='0'+(value%10);
		value/=10;
	}
	pStr[length] = '\0';
	if(negative) pStr[0] = '-';
	
	return pStr;
}

//divide interger
int divide(int dividend, int divisor) {  
	int sign = 1;  
	if(dividend < 0)  
		sign *= -1;  
	if(divisor < 0)  
		sign *= -1;  

	long long big = abs((long long)dividend);  
	long long small = abs((long long)divisor);  
	long long temp = small;  
	long long midres = 1;  
	while(temp < big)  
	{  
		temp <<= 1;  
		midres <<= 1;  
	}  

	int ret = 0;  
	while(temp >= small)  
	{  
		while(big >= temp)  
		{  
			big -= temp;  
			ret += midres;  
		}  
		temp >>= 1;  
		midres >>= 1;  
	}  
	return ret*sign;  
} 


/************************************************************************
Conversion from uppercase to lower case using c program
*************************************************************************/
/*Algorithm:


ASCII value of 'A' is 65 while 'a' is 97. Difference between them is 97 – 65 = 32
So if we will add 32 in the ASCII value of 'A' then it will be 'a' and if will we subtract 32 in ASCII value of 'a' it will be 'A'. It is true for all alphabets.
In general rule:
Upper case character = Lower case character – 32
Lower case character = Upper case character + 32
*/
 #include<stdio.h>
#include<string.h>
int main(){
  char str[20];
  int i;
  printf("Enter any string->");
  scanf("%s",str);
  printf("The string is->%s",str);
  for(i=0;i<=strlen(str);i++){
      if(str[i]>=65&&str[i]<=90)
       str[i]=str[i]+32;
  }
  printf("\nThe string in uppercase is->%s",str);
  return 0;
}



/**
Implemention of strstr()
const char * strstr ( const char * str1, const char * str2 );
Returns a pointer to the first occurrence of str2 in str1, or a null pointer if str2 is not part of str1.
**/

const char * strstr ( const char * str1, const char * str2 )s{
	if(!str) return NULL;
	if(strlen(str2)>strlen(str1))	return NULL;
	char *str1_occur = NULL;
	char *str2_tmp = str2;
	int length = strlen(str) - strlen(str2);
	for(int i=0;i<length;i++){
		if(*str1 == *str2){//check the first character occur
			str1_occur = str1;
			for(int j=1;j<strlen(str2);j++){// from then on, check whether 
				if(*str1_occur++ != *str2_tmp++)
					break;
			}
			if(*str2_tmp++ == '\0') return str1;
		}
		str1++;
	}
	
	return NULL;
}

//recommended implementation by Facebook
const char * strstr ( const char * str1, const char * str2 ){
	for(;;++str1){
		char *h = str1;
		for(char *n = str2;;++n,++h){
			if(!*n) return str1;
			if(*h!=*n) break;
		}
		if(!*h) return NULL;
	}
}

//also we can use hash table

/**********************************************************************************************************************
											
											Remove Duplicate


************************************************************************************************************************/

/**
PIE: Delete characters from a string 
"battle of these" a remove "ae", as "bttl of ths"
**/
void RemoveChars(char str[], char remove[]){

	char removeArr[256];
	
	for(int i=0;i<256;i++){
		removeArr[i] = 0;
	}
	
	int src,dst = 0;
	while(remove[src]){
		removeArr[remove[src]] = 1;
		src++;
	}
	
	src = dst = 0;
	do{
		if(!removeArr[str[src]])
			str[dst++] = str(src);
	}while(str[src++])
	
}

//a extended version
/*
Remove duplicate char(number) in a string(array),
*/
vector<int> removeDup(char *s, int len){
	vector<int> result;
	bool find[256] = {false};   //if all digital, bool[10]
	for(int i=0;i<len;i++){
		if(!find[s[i]]){
			result.push_back(s[i]);
			find[s[i]] = true;
		}
	}
	return result;
}

//this is th most common way, however, could we do it inplace?and use only one loop without known the len?
char *removeDup(char *s){
	char *result = s;
	char *temp = s;
	bool find[256] = {false}; 
	
	do{
		if(!find[*result])
			find[*result] = true;
		else
			temp++;
	}while(*result++=*temp++);
}

/*
Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
Do not allocate extra space for another array, you must do this in place with constant memory.
For example,
Given input array A = [1,1,2],
Your function should return length = 2, and A is now [1,2].
*/
int removeDuplicates(int A[], int n) {

	if(n==0)  return 0;
	int j = 0;
	for(int i=1;i<n;i++){
		if(A[i]!=A[j]){
			j++;
			A[j] = A[i];
		}
	}
	
	return j+1;
}
/*
Follow up for "Remove Duplicates":What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].
*/
int removeDuplicates(int A[], int n) {

	if(n==0)  return 0;
	int j = 0;
	int counter = 0;
	for(int i=1;i<n;i++){
		if(A[i]!=A[j]){
			j++;
			A[j] = A[i];
			counter = 0;
		}else{
			counter++;
			if(counter>1){
				j++;
				A[j] = A[i];
			}
		}
	}
	
	return j+1;
	
	
}

/*
Remove Duplicates from Sorted List
Given a sorted linked list, delete all duplicates such that each element appear only once.
For example,
Given 1->1->2, return 1->2.
Given 1->1->2->3->3, return 1->2->3.
*/
ListNode *deleteDuplicates(ListNode *head) {

	
}

/*
Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.

For example,
Given 1->2->3->3->4->4->5, return 1->2->5.
Given 1->1->1->2->3, return 2->3.
*/
ListNode *deleteDuplicates(ListNode *head) {
	ListNode* start = head;
	ListNode* tmp;
	bool remove = false;

	
	if(head == NULL || head->next == NULL) return head;
	
	while(head->next != NULL){
		if(head->next->val == head->val){
			tmp = head->next;
			free(head);
			head = tmp;
			remove = true;
		}else{
			if(remove){
				tmp = head->next;
				free(head);
				head = tmp;
				remove = false;
				start = head;
			}else{
				head = head->next;	
			}
		}
	}
	
	return start;
	
}


/*
Longest string without repeating character

Given a string, find the length of the longest substring without repeating characters. For example, the longest substring without repeating letters for "abcabcbb" is "abc", which the length is 3. For "bbbbb" the longest substring is "b", with the length of 1.
*/
int lengthOfLongestSubstring(string s) {
     int start = 0;
     int end = 0; 
     int maxlen = 0;
     int i;
	int flag[256] = {0};

	for(i=0;i<s.length();i++){
		if(!flag[s[i]]){
			flag[s[i]] = 1;
		}else{
			if(i-start>maxlen)
                maxlen = i-start;
			while(start<i){
				if(s[start] == s[i]){
					start++;
					break;
				}else{
					flag[s[start]] = 0;
					start++;
				}
			}
		}
	
	}
    
	if(i-start>maxlen)
		maxlen = i-start;
	
	return maxlen;       

	
}



/**
Careercup 2.3
You are given an array of integers (both positive and negative). Find the continuous sequence with the largest sum. Return the sum. 
EXAMPLE
input: {2, -8, 3, -2, 4, -10}
output: 5 [ eg, {3, -2, 4} ]

further step, mark the begin and end of the sub sequence.
**/
int Find_max_sum(const char *a, int len){
	int maxsum = 0;
	int sum = 0;
	int begin,end = 0;
	int len = 0;
	for(int i=0;i<len;i++){
		sum += a[i];
		if(maxsum < sum){
			maxsum = sum;
			begin = i;
			len++;
		}
		else if(sum < 0){
			sum = 0;
		}
	}
	
	end = begin +len -1;
	
	return maxsum;
}


/**
PIE Reverse words in string "I do like NFL" -> "NFL like do I"
**/
void ReverseWords(char str[]){
	int str_len = 0;
	str_len = strlen(str);
	//char *reversed = malloc(sizeof(char)*str_len);
	ReverseStr(str,str_len);

	char *current_str;
	int start = 0;
	strlen = 0;
	while(str[strlen+start]!='\0'){
		strlen = 0;
		while(str[strlen+start]!=' '){
			strlen++;
		}
		current_str = str + start;		
		ReverseStr(current_str,strlen);
		start += strlen+1;   //skip space;
	}
}

void ReverseStr(char str[]){
	
	int len = strlen(str);
	char *start = str;
	char *end = str + len;
	while(end>start){
		temp = *start;
		*start = *end;
		*end = temp;
		start++;end--;
	}
	
}

char *string_reverse2(const char *string)
{
    int len; 
    char * res;

	len = strlen(string);
	char *str = (char*)string + len -1;

    if(!(res = (char*) malloc(len + 1))) return NULL;

	char *ret = res;

    while (len > 0) {
        *ret++ = *str--;
        len--;

    }

    *ret = '\0';

    return res;   

}

/**implement strcpy, considering the memory overlap/
/*
if a > b; then
    copy a from the beginning
else if a < b; then
    copy a from the ending
else // a == b
    do nothing
*/
char* my_strcpy(char *a, char *b){
	if(!a || !b)
		return NULL;
	
	if(a == b)
		return a;
		
	if(a<b){
		char *temp = a;
		while(*b){
			*a++=*b++;
		}
		*a = '\0';
		return temp;
	}
	
	if(a>b){
		int len = strlen(b);
		char *src = b + len; //include '\0'
		char *dest = a + len;//include '\0'
		while(src >= b){
			*dest-- = *src--;
		}
		
		return a;		
	}
}
//Two major methods used in array/string mulipulation: Sort first or Hash. Also ASCII code and its exchange between char and INT


/************
Bit Manipulation and low level stuff
**************/
/*
Swap odd and even bit
*/
int SwapOddEvenbits(int x){
	return ((x&0xaaaaaaaa)>>1) | (x&0x55555555)<<1))
}

/*
Detect whether a number is 2's power
*/
bool Istwopower(int n)
{
	if((n&(n-1)) == 0)
		return true;
	else
		return false
}

return (num != 0) && ((num & (num - 1)) == 0);

/*
Detect how many "1" in one int
*/
//method 1, shift and &
int Numofone(int x){
	int count = 0;
	for(i=0;i<sizeof(int)*8;i++){
		if(x&0x00000001) count++;
		x = x>>1;
	}
	
	return count;
}

//method 2, using a array or hash table to search

//method 3
int Numofone(int x){
	x = (x & 0x55555555) + ((x>>1) & 0x55555555);
	x = (x & 0x33333333) + ((x>>2) & 0x33333333);
	x = (x & 0x0f0f0f0f) + ((x>>4) & 0x0f0f0f0f);
	x += (x>>8);
	x += (x>>16);
	return (x & 0x00ff);
}

//method 4:
int Numofone(int x){
	int count = 0;
	if(x == 0) count = 0;

	do{
		count++;
	}while(x&=(x-1));
	
	return count;
}

int Numofone(int x){

    int counter =0;
    for(;x!=0;x&=(x-1)){
        count++;
    }
    
    return counter;

}

/*
Detect endianness of machine
*/
#define BIG_ENDIAN 0
#define LITTLE_ENDIAN 1
int TestEndian(){
	int test = 1;
	char *test_char = (char *)(&test);
	if(*test_char == 1)
		return LITTLE_ENDIAN;
	else
		return BIG_ENDIAN;
}

/*
Write an aligned malloc & free function that takes number of bytes and
aligned byte (which is always power of 2)
EXAMPLE
align_malloc (1000,128); it will return a memory address that is a
multiple of 128 and points to memory of size 1000 bytes. aligned_
free(); it will free memory allocated by align_malloc.

Career Cup 13.9, pg 182
*/
void* aligned_malloc(size_t required_bytes, size_t alignment) {
	void* p1; // original block
	void** p2; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) {
		return NULL;
	}
	p2 = (void**)(((size_t)(p1) + offset) & ~(alignment - 1));
	p2[-1] = p1;
	return p2;
}
void aligned_free(void *p) {
	free(((void**)p)[-1]);
}

//My code:
/*
http://jongampark.wordpress.com/2008/06/12/implementation-of-aligned-memory-alloc/
*/
void* aligned_malloc(size_t required_bytes, size_t alignment) {
	void* p1; // original block
	void** p2; // aligned block
	int offset = alignment - 1 + sizeof(void*);
	if ((p1 = (void*)malloc(required_bytes + offset)) == NULL) {
		return NULL;
	}
	p2 = (void **)(((size_t)(p1) + offset) & ~(alignment - 1));
	*((void **)p2-1)=p1;
	return p2;
}
void aligned_free(void *p) {
	free(*((void **)p-1));
}

//implement memmove using memcpy
void * memmove ( void * destination, const void * source, size_t num ){

}

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
	while(!ptr){
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

/********************************************************************* 
Given an unsorted integer array, find the first missing positive integer.

For example,
Given [1,2,0] return 3,
and [3,4,-1,1] return 2.

Your algorithm should run in O(n) time and uses constant space. 
************************************************************************/
//return the first missing positive integer
//Bit vector
/*
enum { BITSPERWORD = 32, SHIFT = 5, MASK = 0x1F };
int n, hi, *x;
void set(int i)  {        x[i>>SHIFT] |=  (1<<(i & MASK)); }
void clr(int i)  {        x[i>>SHIFT] &= ~(1<<(i & MASK)); }
int  test(int i) { return x[i>>SHIFT] &=  (1<<(i & MASK)); }
*/
int Firstmissing(int A[], int n){

    int i,j;
        
    int length = 65536;
	int bitarray[65536] = {0};


    for(i=0;i<n;i++){
        if(A[i]<0) continue;
            
        bitarray[A[i]>>5] |=1<<(A[i]&0x1F);
    }
        
    for(i=0;i<length;i++){
        if(bitarray[i]^0xFFFF !=0){
            for(j=0;j<32;j++){
                    
                if((bitarray[i]&(1<<j)) ==0){
                    int first = (i<<5)+j;
                    if(first) return first;
                }
            }

        }
    }
        
	return 0;
}


//another idea: switch A[i] to A[A[i]-1] 
//because we need to avoid 0, so we do this 
int firstMissingPositive(int A[], int n) {
	// Start typing your C/C++ solution below
	// DO NOT write int main() function
	for(int i=0;i<n;i++){
		while(A[i]!=i+1){
			if(A[i] <= 0 || A[i] > n || A[i] == A[A[i]-1]) break;
			int temp = A[i];
			A[i] = A[temp-1];
			A[temp-1] = temp;
		}
	}
	for(int i=0;i<n;i++){
		if(A[i]!=i+1)   return i+1;
	}
	return n+1;
}

/******************************************
find K-th smallest
******************************************/
int findKthSMallest(int[] A, int[] B, int k) {
	int a_offset = 0, b_offset = 0;
	if (A.length + B.length < k) return -1;

	while (true) {
		if (a_offset < A.length) {
			while (b_offset == B.length ||A[a_offset] <= B[b_offset]) {
				a_offset++;
				if (a_offset + b_offset == k) return A[a_offset];
			}
		}
		if (b_offset < B.length) {
			while (a_offset == A.length ||A[a_offset] >= B[b_offset]) {
				b_offset++;
				if (a_offset + b_offset == k) return B[b_offset];
			}
			
		}
	}
}

//Write a program to find the square root of a given numbe

//Binary search again.
double GetSquareRoot(double f, double exp)
{
    assert((f > 0.0 || abs(f) < exp) && exp > 0.0);

    double dbBeg = 0.0;
    double dbEnd = f;

    if (f < 1.0) dbEnd = 1.0;

    int nCount = 100;
    do
    {
        double dbMid = (dbBeg + dbEnd)/2.0;
        double dbSqrDiff = dbMid*dbMid - f;
        if (abs(dbSqrDiff) < exp)
            break;
        if (dbSqrDiff < 0.0)
            dbBeg = dbMid;
        else
            dbEnd = dbMid;
    } while (nCount-- >= 0);

    return (dbBeg + dbEnd)/2.0;
}

//pring matrix in sprial order
/*



*/
// function to print the top-right peel of the matrix and 
// recursively call the print bottom-left on the submatrix.
void printTopRight(int a[][COL], int x1, int y1, int x2, int y2) {
    int i = 0, j = 0;

    // print values in the row.
    for(i = x1; i<=x2; i++) {
        printf("%d ", a[y1][i]);
    }

    // print values in the column.
    for(j = y1 + 1; j <= y2; j++)         {
        printf("%d ", a[j][x2]);
    }

    // see if more layers need to be printed.
    if(x2-x1 > 0) {
        // if yes recursively call the function to 
        // print the bottom left of the sub matrix.
        printBottomLeft(a, x1, y1 + 1, x2-1, y2);
    }
}

// function to print the bottom-left peel of the matrix and 
// recursively call the print top-right on the submatrix.
void printBottomLeft(int a[][COL], int x1, int y1, int x2, int y2) {
    int i = 0, j = 0;

    // print the values in the row in reverse order.
    for(i = x2; i>=x1; i--) {
        printf("%d ", a[y2][i]);
    }

    // print the values in the col in reverse order.
}



/*
Compare version(SW version)

5.01 > 4.99.6 > 3.0 > 1.2.3
2.01>2.0.1
2
*/	

const char *compVersion(const char *version1, const char * version2){
	const char *v1 = version1;
	const char *v2 = version2;
	//compare the digit before first '.'
	if(getNum(v1)>getNum(v2)) return v1;
	else if(getNum(v1)>getNum(v2))  return v2;
	
	while((*v1!='\0')&&(*v2!='\0'){
		if((*v1-'0')>(*v2-'0')) return v1;
		else if((*v1-'0')<(*v2-'0')) return v1;
		
		if((*v1=='.') && (*v1=='.')){
			v1++;
			v2++;
		}else if(*v1=='.'){
			return v2;
		}else if(*v2=='.'){
			return v1;
		}
		

	}
	
	if(v1) return v1;
	if(v2) return v2;

}

int getNum(const char* str){
	int num = 0;
	while(*str!=='.'){
		num = num*10+(*str-'0');
		str++;
	}
	
	return num;
}
	
/*
define a data structure to bignumber to represent any size digit,

perform add and multiple
*/
//considering plus,minus
typedef list<char> bignum;

bignum addUp(bignum a, bignum b){

	int carry = 0;
	int tmp = 0;
	bignum sum;
	int neg_a = 0;
	int neg_b = 0;
	if(a.front()== '-'){ 
		neg_a = 1;
		a.pop_front();
	}
	if(b.front() == '-'){ 
		neg_b = 1;
		b.pop_front();
	}
	
	if(!(neg_a^neg_b)){

		
		while(!a.empty() || !b.empty()){
			if(a.empty())  {
					tmp = (b.back() - '0') + carry;
					b.pop_back();
			}else if(b.empty()){
					tmp = (a.back()-'0') + carry;
					a.pop_back();
			}else{
				tmp = (a.back() - '0') + (b.back()-'0') + carry;
				a.pop_back();
				b.pop_back();
			}
			
			if(tmp>=10)	
				carry = 1;
			else
				carry = 0;
			
			sum.push_front(tmp%10+'0');
		}
		
		if(carry == 1) sum.push_front('1');
		
		if((neg_a == 1) && (neg_b == 1)) sum.push_front('-');
	}
	
	
		
	return sum;
}

bignum multi(bignum a,bignum b){
	
	//switch for efficiency
	if(smaller(a,b)){
		bignum tmp;
		tmp = a;
		a = b;
		b = tmp;
	}
	
	
	bignum result;
	result.push_back('0');
	bignum step;
	step.push_back('1');
	bignum multiplier;
	multiplier.push_back('0');
	
	while(smaller(multiplier,b)){
	
		result = addUp(a, result);
		multiplier = addUp(multiplier, step);
		
	}
	
	return result;
}

//if a is smaller than b, return true, otherwise return false;
bool smaller(bignum a,bignum b){
	
	if(a.size()<b.size()){
		return true;
	}else if(a.size()>b.size()){
		return false;
	}else{
		while(!a.empty() && !b.empty()){
			if((a.front()-'0')<(b.front()-'0')){
				return true;
			}else if((a.front()-'0')>(b.front()-'0')){
				return false;
			}else{
				a.pop_front();
				b.pop_front();
			
			}
		}
	}
		
	return false;// for equal
}

//missing position: 
/*
“abc”, “ab” => print  “2”
“abc”, “b” => print “0 2”
“abc”, “ac” => print “1”
“aab”, “ab” =>  print “0”   OR   print “1”
*/
vector<int> charMissing(string s1, string s2){
	
	vector<int> missing;
	int i=0,j=0;

	while(j<s2.size()){
		while(i<s1.size()){
			if(s2[j]!=s1[i]){
				missing.push_back(i);
				i++;
			}else{
				j++;
				i++;
				break;
			}
		}
		break;//if s2 has some char s1 dose not have
	}

	while(i<s1.size()){
		missing.push_back(i);
		i++;
	}

	return missing;

}

/*
Given a non-negative integer array representing an elevation map whereas the width of each bar is 1, compute how much water it can contain after 
raining. For example, given [0,1,0,2,1,0,1,3,2,1,2,1], returns 6. What is the complexity of your solution?
*/
int waterContainer(int array[]){
	


}

/*
From the set of natural integer numbers
Let x = 1234 = {1, 2, 3, 4}
Let y = 2410 = {2, 4, 1, 0}

Write an algorithm to compute the rearrangement of x that is closest to y but still greater than y. Both x and y have the same number of digits.

So in the example above, the answer would be { 2, 4, 1, 3 } = 2413 which is greater than y = 2410 and closer than any other arrangements of x.

And whats the time complexity of this algorithm?
*/

int reArrange(int x[],int y[]){
	

}
/*
Permutation of String

*/
/*idea 1: recursive: permutation is to pickup a char at a given position and perform permutation at next position.
staring at n, do permutate for n+1, in order to remove duplicate, we need to mark char used current

permutation(abcd) = a+permutation(bcd) + b+permutation(acd)....

*/
int Permutate(char instring[]){
	
	int length = strlen(instring);
	
	if(!(out = (char*)malloc(sizeof(char)*length+1))) return 0;
	out[length+1] ='\0';
	
	if(!used = (int*)malloc(sizeof(int)*length)) return 0;
	
	for(int i = 0;i<length;i++){
		used[i] = 0;
	}
	
	doPermutation(instring, out, used,length,0);
	
	free(used);
	free(out);
	
	return 1;
}



void doPermutation(char in[], char out[], int used[], int length, int recurloc){
	int i;
	
	if(recurloc ==  length){
		printf("%s\n",out);
		return;
	}
	
	for(i=0;i<length;i++){
		if(used[i]) continue;   //check whether this char has been used, remove duplicate
		
		out[recurloc] = in[i];   //place char at this location,
		used[i] = 1;
		doPermutation(in, out, used, length, recurloc+1);
		used[i] = 0;
	}

}

/*
method 2:swap based; "abc" for example:
						abc
swap first:	abc			bac           cba
swap second acb 		bca			  cab

*/
 
/* Function to print permutations of string
   This function takes three parameters:
   1. String
   2. Starting index of the string
   3. Ending index of the string. */
void permute(char *a, int i, int n)
{
   int j;
   if (i == n)
     printf("%s\n", a);
   else
   {
        for (j = i; j <= n; j++)
       {
          swap((a+i), (a+j));
          permute(a, i+1, n);
          swap((a+i), (a+j)); //backtrack
       }
   }
} 


/*
Any size reader: 
int block_reader(char *buf), a internal static pointer that can only be moved towards end of file. everytimr only reads 4K into buffer and return # of bytes read
implement int anysize_reader(char *buf, int size) 
*/
int b_nSize= 0;
int anysize_reader(char *buf, int size){
	if (size == 0) return 0;
	int left;
	int finished;
	
	//memcpy(buf, b_buf, b_nSize);

	if (size <= b_nSize)
	{
		memcpy(buf, b_buf, size);
		b_nSize = b_nSize - size;
		memcpy(b_buf,b_buf+size,b_nSize);   //align the remaing chuck to 4K block boundary since b_buf can not be rewind.

		return size;
	}

	memcpy(buf, b_buf, b_nSize);
	buf += b_nSize;
	left = size-b_nSize;
	finished = b_nSize;

	b_nSize = blockReader(m_buf);
	//at the end of the file.
	if(b_nSize<4096 && left>b_nSize){
		memcpy(buf,b_buf,b_nSize);
		return finished + b_nSize;
	}
	
	return finished + anysize_reader(buf, left);

} 

//probablity
/*
reject sampling
Given a function which generates a random integer in the range 1 to 7, write a function which generates a random integer in the range 1 to 10 uniformly.
The main idea is when you generate a number in the desired range, output that number immediately. If the number is out of the desired range, 
reject it and re-sample again. As each number in the desired range has the same probability of being chosen, a uniform distribution is produced.
*/
int rand10() {
  int row, col, idx;
  do {
    row = rand7();
    col = rand7();
    idx = col + (row-1)*7;
  } while (idx > 40);
  return 1 + (idx-1)%10;
}

/*
shuffle deck
*/
/*
Let X1, X2…. XN (In this case N=52) be the set of N numbers to be shuffled.

    Set j to N
    Generate a random number R. (uniformly distributed between 0 and 1)
    Set k to (jR+1). k is now a random integer, between 1 and j.
    Exchange Xk and Xj
    Decrease j by 1.
    If j > 1, return to step 2.
	*/

void KnuthShuffle(int* pArr) 
{ 
    int rand; 
    for(int i=51;i>=0;i--) 
    { 
        rand=GenRand(0,i); 
        swap(pArr[i], pArr[rand]); 
    } 
}

//shuffle a array:
for (int i= size-1 ; i > 0; i--) {
	// generate a random number between a range from 0:i-1
	int j = (int)( Math.random () * 100) % i;
	// swap myArray[i] with myArray[j]
	int temp = myArray[i];
	myArray[i] = myArray[j];
	myArray[j] = temp;
}

void ShuffleArray_Fisher_Yates(char* arr, int len)
{
    int i = len, j;
    char temp;
 
    if ( i == 0 ) return;
    while ( --i ) {
        j = rand() % (i+1);
        temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

/*
given random generator rand(int n),now, design a random generator such as

rand(int n, int[] except).
example, n=10, random 1-10
now, except[3]={1,5,6}
then rand(10, except) output {2,3,4, 7, 8, 9,10}

*/





#include <string>
#include <iostream>
#include <fstream>
#include "strtk.hpp"



#include <iostream>

enum bid_status{bid, offer};
enum quote_status{newone,update, deleteone};


struct quote{
	char e_id;
	char quote_bid;
	char quote_status;
	int quote_price;
	int quote_vol;
}


class miniBook{
	public:
	miniBook();
	~minbook();
	vector<quote> offer_quote;
	vector<quote> bid_quote;

		
	void parseInput(char* filename, int len);//len is assumed to be known
	void sortPrice(vector<quote> raw_quote);

}

minBook::miniBook{

}

minBook::~miniBook{

}

miniBook::void parseInput(char* filename,int len){
	
	
	ifstream file(filename);
	while(file.good()){
		String s;
		getline(file,s);
		quote tmp;
		//in correct input should be handled here:

		strtk::parse(s,"/",tmp.quote_id,tmp.quote_bid,tmp.quote_status,tmp.quote_price,tmp.quote_vol);
		if()	

	}
}


minBook::bool compPrice(bool small){
	if(small)

}

minBook::bool compVol(bool small){


}

minBook::sort(comparator,vector<quote> raw_quote){
	if(raw_quote.begin().quote_id == 'B'){
		sort(offer_quote.begin(), offer_quote.end(), compPrice());
	}
	if(raw_quote.begin().quote_id == 'O'){
		sort(offer_quote.begin(), offer_quote.end(), sortPrice);
	}

}


bool sumValid(Node *node,int &sum, int target){
	
	if(!node) return false;
	if(node->val+sum == target){
		return true;
	}else if(node->val+sum < target){
		if(sumValid(node->left,node->val+sum,target))
			return true;
		if(sumValid(node->right,node->val+sum,target))
			return true;
	}
	
	return false;
}


		
	
