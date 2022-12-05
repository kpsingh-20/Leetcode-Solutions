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
Node* middleNode(Node* head) 
{
	Node *slow = head;
	Node *fast = head;

	while(fast->next and fast->next->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	if(fast->next){
		return slow->next;
	}
	return slow;
}
};