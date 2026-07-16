// Last updated: 16/07/2026, 09:30:26
1#include<numeric>
2class Solution {
3public:
4    long long gcdSum(vector<int>& nums) {
5        vector<int> prefix_maxi(nums.size());
6        prefix_maxi[0] = nums[0];
7        for(int i=1;i<nums.size();i++){
8            prefix_maxi[i] = max(nums[i],prefix_maxi[i-1]);
9        }
10        vector<int> prefixgcd(nums.size());
11        for(int i=0;i<nums.size();i++){
12            prefixgcd[i] = gcd(nums[i],prefix_maxi[i]);
13        }
14        sort(prefixgcd.begin(),prefixgcd.end());
15        vector<int> vis(prefixgcd.size());
16        long long sum = 0;
17        int i = 0;
18        int j = prefixgcd.size() - 1;
19        while(i < j){
20            sum += gcd(prefixgcd[i],prefixgcd[j]);
21            i++;
22            j--;
23        }
24        return sum;
25    }
26};