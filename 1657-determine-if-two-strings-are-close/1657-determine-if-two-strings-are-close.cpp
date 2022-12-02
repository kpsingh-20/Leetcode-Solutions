class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>

bool closeStrings(string word1, string word2) 
{
    int n1 = word1.size();
    int n2 = word2.size();

    vi hash1(26, 0);
    vi hash2(26, 0);

    for(int i=0; i<n1; i++){
        hash1[word1[i] - 'a']++;
    }
    for(int i=0; i<n2; i++){
        hash2[word2[i] - 'a']++;
    }
    for(int i=0; i<26; i++){
        if(hash1[i] == 0 and hash2[i] != 0){
            return 0;
        }
        if(hash1[i] != 0 and hash2[i] == 0){
            return 0;
        }
    }
    sort(all(hash1));
    sort(all(hash2));

    for(int i=0; i<26; i++){
        if(hash1[i] != hash2[i]){
            return 0;
        }
    }
    return 1;
}
};