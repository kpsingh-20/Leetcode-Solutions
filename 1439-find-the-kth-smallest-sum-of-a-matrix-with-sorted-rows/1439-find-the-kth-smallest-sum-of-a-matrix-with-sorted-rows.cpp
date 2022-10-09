class Solution {
public:

#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define 	vvc					std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>

int kthSmallest(vvi& mat, int k) 
{
	vi indexes; 
	int n = mat.size();
	int m = mat[0].size();

	int sum = 0;
	for(int i=0; i<n; i++){
		sum += mat[i][0];
		indexes.pb(0);
	}

	set<pair<int, vi>> set;
	set.insert({sum, indexes});

	int t = 1;
	while(!set.empty())
	{	
		if(t++ == k){
			break;
		}

		int curr = (*set.begin()).ff;
		vi vec = (*set.begin()).ss;
		set.erase(set.begin());

		// cout << curr;br;
		// coutspace(vec);br;br;
		for(int i=0; i<n; i++){
			if(vec[i] < m-1){
				curr = curr + mat[i][vec[i] + 1] - mat[i][vec[i]];
				vec[i]++;
				set.insert({curr, vec});
				vec[i]--;
				curr = curr - mat[i][vec[i] + 1] + mat[i][vec[i]];
			}
		}

	}

	return (*set.begin()).ff;
}
    
};