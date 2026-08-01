// Last updated: 01/08/2026, 14:54:44
1class Solution {
2public:
3    bool predictTheWinner(vector<int>& nums) {
4        int n = nums.size();      
5        if (n % 2 == 0) return true; 
6        vector<int> dp(nums);
7        for(int i=n-2;i>=0;--i){
8            for(int j=i+1;j<n;++j){
9                dp[j] = max(nums[i] - dp[j], nums[j] - dp[j - 1]);
10            }
11        }
12        return dp[n - 1] >= 0;
13    }
14};