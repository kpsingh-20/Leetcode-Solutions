class Solution {
public:
    
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvc                 std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>

    
string frequencySort(string s) 
{
    std::map<char, int> map;
    for(int i=0; i<s.size(); i++){
        map[s[i]]++;
    }

std::vector<pair<int, char>> v;
    for(auto x : map){
        v.pb({x.ss, x.ff});
    }
    sort(all(v));

    string ret;
    for(int i=0; i<v.size(); i++){
        for(int j=0; j<v[i].ff; j++){
            ret.pb(v[i].ss);
        }
    }
    reverse(all(ret));
    return ret;
}

};