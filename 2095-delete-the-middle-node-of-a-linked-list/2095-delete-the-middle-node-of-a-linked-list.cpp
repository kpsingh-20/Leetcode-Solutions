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
Node* deleteMiddle(Node* head) 
{
	Node* root = new Node(-1);
    root->next = head;
    	
    Node *temp = root;

	int n = 0;
	while(temp){
		n++;
		temp = temp->next;
	}

    n--;
	if(n&1){
		n = n/2;
	}else{
		n = n/2;
	}

	// cout << n;br;

	temp = root;
	while(n){
		temp = temp->next;
		n--;
	}

	temp->next = temp->next->next;
	return root->next;
}

};