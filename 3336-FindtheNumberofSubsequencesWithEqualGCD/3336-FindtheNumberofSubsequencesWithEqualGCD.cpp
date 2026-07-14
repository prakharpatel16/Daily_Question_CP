// Last updated: 14/07/2026, 14:51:37
1class Solution {
2public:
3    const int MOD = 1e9 + 7;
4    int subsequencePairCount(vector<int>& nums) {
5        int maxi = *max_element(nums.begin(),nums.end());
6        vector<vector<int>> prev(maxi+1,vector<int>(maxi+1, 0));
7        for(int first=0;first<=maxi;first++){
8            for(int second=0;second<=maxi;second++){
9                int bothNonEmpty = (first != 0) and (second != 0);
10                int GcdMatched = (first == second);
11                prev[first][second] = (bothNonEmpty and GcdMatched) ? 1 : 0;
12            }
13        }
14        for(int i=nums.size()-1;i>=0;i--){
15            vector<vector<int>> curr(maxi + 1, vector<int>(maxi + 1, 0));
16            for(int first=maxi;first>=0;first--){
17                for(int second=maxi;second>=0;second--){
18                    int skip = prev[first][second];
19                    int take1 = prev[__gcd(first,nums[i])][second];
20                    int take2 = prev[first][__gcd(second,nums[i])]; 
21                    curr[first][second] = (1LL * skip + take1 + take2) % MOD;
22                }
23            }
24            prev = move(curr);
25        }
26        return prev[0][0];
27    }
28};