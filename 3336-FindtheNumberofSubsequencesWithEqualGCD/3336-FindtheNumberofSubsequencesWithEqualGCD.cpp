// Last updated: 14/07/2026, 14:44:09
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    int subsequencePairCount(vector<int>& nums) {
5        int maxi = *max_element(nums.begin(),nums.end());
6        int dp[nums.size()+1][maxi+1][maxi+1];
7        for(int first=0;first<=maxi;first++){
8            for(int second=0;second<=maxi;second++){
9                int bothNonEmpty = (first != 0) and (second != 0);
10                int GcdMatched = (first == second);
11                dp[nums.size()][first][second] = (bothNonEmpty and GcdMatched) ? 1 : 0;
12            }
13        }
14        for(int i=nums.size()-1;i>=0;i--){
15            for(int first=maxi;first>=0;first--){
16                for(int second=maxi;second>=0;second--){
17                    int skip = dp[i+1][first][second];
18                    int take1 = dp[i+1][__gcd(first,nums[i])][second];
19                    int take2 = dp[i+1][first][__gcd(second,nums[i])]; 
20                    dp[i][first][second] = (1LL * skip + take1 + take2) % MOD;
21                }
22            }
23        }
24        return dp[0][0][0];
25    }
26};