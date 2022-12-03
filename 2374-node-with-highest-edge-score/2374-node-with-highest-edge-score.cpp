class Solution {
public:
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvc                 std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second

int edgeScore(vector<int>& edges) 
{
    std::map<long long, long long> map;

    for(int i=0; i<edges.size(); i++){
        map[edges[i]] += i;
    }

    int maxi = INT_MIN;
    ll ans = 0;

    for(auto x : map)
    {
        if(maxi < x.ss){
            maxi = x.ss;
            ans = x.ff;
        }else if(maxi == x.ss){
            ans = min(ans, x.ff);
        }
    }
    return ans;

}
};