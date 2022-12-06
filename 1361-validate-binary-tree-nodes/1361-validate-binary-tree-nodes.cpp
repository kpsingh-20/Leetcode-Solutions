class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     ll                 long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     all(a)              a.begin(),a.end()
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     fi(i,a,b)           for(int i=a; i<b; i++)
#define     fie(i,a,b)          for(int i=a; i<=b; i++)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)         for(int i=0; i<n; i++) cin >> a[i];
#define     make_graph(g,n,m)   for(int i=0; i<m; i++){int v1,v2; cin >> v1 >> v2; g[v1].pb(v2);g[v2].pb(v1);}
#define     M                  	1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
// #define     ans(t,k)            cout << "Case #"<< t << ": " << k;
#define 	coutvvi(grid)				for(auto &x: grid){ coutspace(x);br; }
#define 	cinvvi(grid)			for(auto &x : grid){cinvec(x);}

// bool isCycleExist(int root, vi g[], vi &vis, int &ct){
// 	// cout << root << " " << vis[root];br;
// 	if(vis[root]) return 1;
// 	vis[root] = 1;

// 	for(auto child : g[root]){
// 		if(isCycleExist(child, g, vis, ct)){
// 			return 1;
// 		}
// 	}
// 	return 0;
// }

// bool validateBinaryTreeNodes(int n, vi& leftChild, vi& rightChild) 
// {
// 	std::vector<int> g[n];

// 	int edges = 0;
// 	vi indegree(n, 0);

// 	for(int i=0; i<n; i++){
// 		if(leftChild[i] != -1){
// 			g[i].pb(leftChild[i]);
// 			edges++;
// 			indegree[leftChild[i]]++;
// 		}
// 		if(rightChild[i] != -1){
// 			g[i].pb(rightChild[i]);
// 			edges++;
// 			indegree[rightChild[i]]++;
// 		}
// 	}
// 	if(edges != n-1){
// 		return 0;
// 	}

// 	int root = -1;
// 	for(int i=0; i<n; i++){
// 		if(indegree[i] > 1) return 0;
// 		if(indegree[i] == 0){
// 			// cout << i << " " << root;br;
// 			if(root != -1){
// 				return 0;
// 			}else{
// 				root = i;
// 			}
// 		}
// 	}	

// 	vi vis(n, 0);

// 	int ct= 0;
// 	if(isCycleExist(root, g, vis, ct)){
// 		return 0;
// 	}

// 	if(ct != n) return 0;
// 	return 1;
// }   
    
    
vi par;
int find(int node)
{
	if(par[node] == -1) return node;
	return 	par[node] = find(par[node]);
}

void Union(int a, int b)
{
	int p = find(a);
	int q = find(b);

	par[q] = p;
}


bool validateBinaryTreeNodes(int n, vi& leftChild, vi& rightChild) 
{
	par = std::vector<int>(n, -1);

	for(int i=0; i<n; i++)
	{
		int l = leftChild[i];
		int r = rightChild[i];

		if(l != -1)
		{
			if(find(l) != l or find(l) == find(i)) 
			{
				return 0;
			}
			Union(i, l);
		}

		if(r != -1)
		{
			if(find(r) != r or find(r) == find(i))
			{
				return 0;
			}
			Union(i, r);
		}
	}
	int x = find(0);                                // After getting wrong asn
	for(int i=0; i<n; i++)
	{
		if(find(i) != x) return 0;
	}

	return 1;
}
};