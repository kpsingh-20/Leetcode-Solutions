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
int pairSum(Node* head) 
{
	std::vector<int> v;
	int n = 0;

	Node *temp = head;
	while(temp){
		n++;
		v.push_back(temp->val);
		temp = temp->next;
	}

	int l = 0, r = n-1;
	int ans = INT_MIN;
	while(l<r){
		ans = max(ans, v[l++] + v[r--]);
	}

	return ans;
}
};