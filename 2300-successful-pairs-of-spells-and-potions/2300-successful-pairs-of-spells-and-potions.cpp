class Solution {
public:

    
    
    
#define     ll                 long long
#define     pb                  push_back
#define     vi                  vector<int>
#define     all(a)              a.begin(),a.end()


bool check(int mid,int a,ll &success, vi &potions)
{
	if(a * 1LL * potions[mid] >= success) return 1;
	return 0;
}

vi successfulPairs(vi& spells, vi& potions, ll success) 
{
	int n = spells.size();
	int m = potions.size();

	sort(all(potions));

	vi ans(n, 0);
	for(int i=0; i<n; i++){
		int s = spells[i];
		int l = 0;
		int r = m-1;	

		while(r - l > 1){
			int mid = (l + r)/2;
			if(check(mid, s, success, potions)){
				r = mid;
			}else{
				l = mid + 1;
			}
		}	
		// cout << s << " " << l << " " << r;br;

		if(check(l, s, success, potions)){	
			ans[i] = m-l;
		}else if(check(r, s, success, potions)){
			ans[i] = m-r;
		}else{
			ans[i] = m - r -1;
		}
	}

	return ans;
}

    
    
    
};