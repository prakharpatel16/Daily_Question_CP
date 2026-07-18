// Last updated: 18/07/2026, 12:11:56
1class Solution {
2public:
3    int GCD(int a, int b)
4    {
5        if(b==0) return a;
6        return GCD(b, a%b);
7    }
8    int findGCD(vector<int>& nums) {
9        int minE=INT_MAX, maxE=INT_MIN;
10        for(int i=0; i<nums.size(); i++)
11        {
12            minE = min(minE, nums[i]);
13            maxE = max(maxE, nums[i]);
14        }
15        return GCD(maxE, minE);
16    }
17};