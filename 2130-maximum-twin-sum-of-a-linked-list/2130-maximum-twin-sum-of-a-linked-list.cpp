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


// This solution uses O(N) space but below solution uses O(1) space as we have reverese the other half of the linkedlist so that we can traverse simultaneously.
class Solution {
public:
// int pairSum(Node* head) 
// {
// 	std::vector<int> v;
// 	int n = 0;

// 	Node *temp = head;
// 	while(temp){
// 		n++;
// 		v.push_back(temp->val);
// 		temp = temp->next;
// 	}

// 	int l = 0, r = n-1;
// 	int ans = INT_MIN;
// 	while(l<r){
// 		ans = max(ans, v[l++] + v[r--]);
// 	}

// 	return ans;
// }
    
    
int pairSum(Node* head) 
{
	Node *slow = head;
	Node * fast = head;

	while(fast and fast->next){
		slow = slow->next;
		fast = fast->next->next;
	}

	Node *pre = NULL;
	Node * temp;
	while(slow){
		temp = slow->next;
		slow->next = pre;
		pre = slow;
		slow = temp;
	}


	// display(head);br;
	// display(pre);br;

	int ans = INT_MIN;
	fast = head;
	while(pre){
		ans = max(ans, pre->val + fast->val);
		pre = pre->next;
		fast = fast->next;
	}
	return ans;
}

};