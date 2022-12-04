class Solution {
public:
#define     test(t)             int t; cin>>t; while(t--)
#define     pb                  push_back
#define     all(a)              a.begin(),a.end()
#define     ll                  long long
#define     vi                  vector<int>
#define     vvi                 vector<vi>
#define     vvvi                vector<vvi>
#define     vvc                 std::vector<std::vector<char>>
#define     ff                  first
#define     ss                  second
#define     pii                 pair<int,int>
#define     setbits(x)          __builtin_popcountll(x)
#define     trailzeroes(x)      __builtin_ctzll(x)
#define     cinvec(a)           for(int i=0; i<a.size(); i++) cin >> a[i];
#define     coutendl(a)         for(auto i: a) cout<<i<<endl;
#define     coutspace(a)        for(auto i: a) cout<<i<<' ';
#define     cinarray(a, n)      for(int i=0; i<n; i++) cin >> a[i];
#define     inf                   1000000007
#define     br                  cout << endl;
#define     no()                return "NO";
#define     yes()               return "YES";
#define     coutvvi(grid)               for(auto &x: grid){ coutspace(x);br; }
#define     cinvvi(grid)            for(auto &x : grid){cinvec(x);}

// double avg(vi nums)
// {
//     double n = nums.size();
//     double sum = 0;

//     for(int i=0; i<nums.size(); i++){
//         sum += nums[i];
//     }

//     return (sum/n);
// }


// bool func(int i, vi &nums, vi &first, vi &second) 
// {
//     int n = nums.size();
//     if(i == n){

//         if(first.size() == 0 or second.size() == 0){
//             return 0;
//         }
//         if(avg(first) == avg(second)) return 1;
//         return 0;
//     }
//     first.pb(nums[i]);
//     if(func(i+1, nums, first, second)) return 1;
//     first.pop_back();

//     second.pb(nums[i]);
//     if(func(i+1, nums, first, second)) return 1;
//     second.pop_back();

//     return 0;
// }

// bool splitArraySameAverage(vector<int>& nums) 
// {
//     vi first, second;
//     return func(0, nums, first, second);

// }
    
// bool func(vi &nums,int ind, int currEle, int currSum, int sum, int ele, vvvi &dp)
// {
//     int n = nums.size();
//     if(ind == n){
//         if(currSum == sum and currEle == ele){
//             return 1;
//         }
//         return 0;
//     }
//     if(currSum == sum and currEle == ele){
//         return 1;
//     }
//     if(currSum > sum) return 0;
//     if(currEle > ele) return 0;

//     if(dp[ind][currEle][currSum] != -1) return dp[ind][currEle][currSum];

//     bool a = func(nums, ind + 1, currEle, currSum, sum, ele, dp);
//     if(a) return dp[ind][currEle][currSum] =  1;

//     bool b= func(nums , ind + 1, currEle + 1, currSum + nums[ind], sum, ele, dp);
//     if(b) return dp[ind][currEle][currSum] = 1;

//     return dp[ind][currEle][currSum] = 0;
// }

// bool splitArraySameAverage(vector<int>& nums) 
// {
//     int sum = accumulate(all(nums), 0);
//     int n = nums.size();

//     for(int i=1; i<=n-1; i++){
//         double s1 = (double)(sum*i)/(double)(n);
//         if(s1 == floor(s1)){
//             vvvi dp(n+1,vvi(n+1, vi(sum+1, -1)) );
//             bool a = func(nums, 0, 0, 0, s1, i, dp);
//             if(a) return 1;
//         }
//     }

//     return 0;
// }
    
// bool func(vi &nums,int ind, int currEle, int currSum, vvvi &dp)
// {
//     if(currEle == 0) return currSum == 0;
//     if(currSum < 0) return 0;
//     int n = nums.size();
//     if(ind >= n){
//         return 0;
//     }

//     if(dp[ind][currEle][currSum] != -1) return dp[ind][currEle][currSum];

//     bool a = func(nums, ind + 1, currEle, currSum, dp);
//     if(a) return dp[ind][currEle][currSum] =  1;

//     bool b= func(nums , ind + 1, currEle - 1, currSum - nums[ind], dp);
//     if(b) return dp[ind][currEle][currSum] = 1;

//     return dp[ind][currEle][currSum] = 0;
// }

// bool splitArraySameAverage(vector<int>& nums) 
// {
//     int sum = accumulate(all(nums), 0);
//     int n = nums.size();
    
//     vvvi dp(n+1,vvi(n+1, vi(sum+1, -1)) );

//     for(int i=1; i<=n-1; i++){
//         double s1 = (double)(sum*i)/(double)(n);
//         if(s1 == floor(s1)){
//             bool a = func(nums, 0, i, s1, dp);
//             if(a) return 1;
//         }
//     }

//     return 0;
// }
    
    
    
    
//     unordered_map<string, int> mp;

// bool func(vi &nums,int ind, int currEle, int currSum)
// {
//     if(currEle == 0) return currSum == 0;
//     if(currSum < 0) return 0;
//     int n = nums.size();
//     if(ind >= n){
//         return 0;
//     }

//     string key = to_string(ind) + "#" + to_string(currEle) + "#" + to_string(currSum);
//     if(mp.count(key)){
//         return mp[key];
//     }
    
    
    
//     if(nums[ind] <= currSum){
//         return mp[key] = func(nums, ind + 1, currEle, currSum) or
//                             func(nums, ind + 1, currEle-1, currSum - nums[ind]);
//     }
//     else{
//         return mp[key] = func(nums, ind + 1, currEle, currSum);
//     }

//     return mp[key] = 0;
// }

// bool splitArraySameAverage(vector<int>& nums) 
// {
//     int sum = accumulate(all(nums), 0);
//     int n = nums.size();
    

//     for(int i=1; i<=n-1; i++){

//         if((sum * i)%n == 0){
//             int s1 = (sum*i)/n;
//             if(func(nums, 0, i, s1))
//                 return 1;
//         }

//     }
//     return 0;
// }
    
        unordered_map<string, int> mp;
    
    bool helper(vector<int>& nums, int i, int n, int sum, int n1)
    {
        // base case
        
        if(n1 == 0)
            return sum == 0;
        
        if(i == n)
            return false;
        
        // create a key
        
        string key = to_string(i) + "#" + to_string(n1) + "#" + to_string(sum);
        
        // if already calculated
        
        if(mp.count(key))
            return mp[key];
        
        // if nums[i] <= sum, then we will either include or exclude
        
        // calculate the result and store in map
       
        if(nums[i] <= sum)
        {
            return mp[key] = helper(nums, i + 1, n, sum - nums[i], n1 - 1) || helper(nums, i + 1, n, sum, n1);
        }
        else
            return mp[key] = helper(nums, i + 1, n, sum, n1);
    }
    
    bool splitArraySameAverage(vector<int>& nums) {
        
        int n = nums.size();
        
        // find the total sum
        
        int sum = 0;
        
        for(int i = 0; i < n; i++)
        {
            sum += nums[i];
        }
        
        // check for every possible size of subset from 1 to n - 1
        
        for(int n1 = 1; n1 < n; n1++)
        {
            if((sum * n1) % n == 0)
            {
                int req_sum = (sum * n1) / n;
                
                // check if there is any subset of n1 that has sum of req_sum
            
                if(helper(nums, 0, n, req_sum, n1))
                    return true;
            }
        }
        
        return false;
    }


};