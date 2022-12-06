/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#define 	Node				ListNode

class Solution {
public:
Node* oddEvenList(Node* head) 
{
    if(!head) return head;
	Node* odd = head;
	Node* even = head->next;

	Node* f = odd;
	Node* s = even;

	while(even and even->next)
	{
		odd->next = even->next;
		even->next = even->next->next;

		odd = odd->next;
		even = even->next;
	}
	odd->next = s;

	return f;

}

};