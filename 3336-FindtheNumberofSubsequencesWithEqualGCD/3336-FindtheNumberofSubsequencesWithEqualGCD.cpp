// Last updated: 14/07/2026, 13:58:05
1class Solution {
2public:
3    int dp[201][201][201];
4    const int MOD = 1e9 + 7;
5    int solve(vector<int> &nums,int i, int first, int second){
6        if(i == nums.size()){
7            bool bothNonEmpty = (first != 0) and (second != 0);
8            bool isMatched = (first == second);
9            return (bothNonEmpty and isMatched) ? 1 : 0;
10        }
11        if(dp[i][first][second] != -1){
12            return dp[i][first][second];
13        }
14        int skip = solve(nums,i+1,first,second);
15        int take1 = solve(nums,i+1,__gcd(first,nums[i]),second);
16        int take2 = solve(nums,i+1,first,__gcd(second,nums[i]));
17        return dp[i][first][second] = (1LL* skip + take1 + take2) % MOD;
18    }
19    int subsequencePairCount(vector<int>& nums) {
20        memset(dp,-1,sizeof(dp));
21        return solve(nums,0,0,0);      
22    }
23};