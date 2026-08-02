// Last updated: 02/08/2026, 23:02:09
1class Solution {
2public:
3    bool stoneGame(vector<int>& piles) {
4        int n = piles.size();
5        vector<int> dp(n, 0);
6        for(int left=n-1;left>=0;left--){
7            for(int right=left;right<n;right++){
8                int turn = (left + right) % 2;
9                if(left == right){
10                    dp[right] = 0;
11                }
12                else{
13                    if(turn){
14                        dp[right] = max(
15                            piles[left] + dp[right],
16                            piles[right] + dp[right - 1]
17                        );
18                    }
19                    else{
20                        dp[right] = min(
21                            dp[right],
22                            dp[right - 1]
23                        );
24                    }
25                }
26            }
27        }
28        int total = accumulate(piles.begin(), piles.end(), 0);
29        return dp[n - 1] > total - dp[n - 1];
30    }
31};