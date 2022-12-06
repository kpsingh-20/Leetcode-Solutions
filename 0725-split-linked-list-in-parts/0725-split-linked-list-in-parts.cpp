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
#define     pb                  push_back

class Solution {
public:
vector<Node*> splitListToParts(Node* head, int k) 
{
	int n = 0;
	Node* temp = head;
	while(temp){
		n++;
		temp = temp->next;
	}

	int eachPart = n/k;
	int oneIncrease = n%k;

	temp = head;
	int size = eachPart;

	std::vector<Node*> parts;
	while(temp)
	{
		size = eachPart;
		// cout << temp->val;br;
		k--;
		if(oneIncrease-- > 0) size++;
		Node* part = temp;
		parts.pb(part);

		size--;
		// cout << size;br;
		while(size--){
			part = part->next;
		}

		temp = part->next;
		part->next = NULL;
	}
	while(k--) parts.pb(NULL);
	return parts;
}
};