class Solution {
public:

int maximumBags(vector<int>& capacity, vector<int>& rocks, int ar) 
{
 	int n = capacity.size();
 	priority_queue<int, std::vector<int>, greater<int>> pq; 	// min heap.

 	for(int i=0; i<n; i++){
 		pq.push(capacity[i] - rocks[i]);
 	}

 	int ans = 0;
 	while(!pq.empty()){
 		int req = pq.top(); pq.pop();

 		if(req > ar){
 			break;
 		}
 		ans++;
 		ar -= req;
 	}
 	return ans;

}
};