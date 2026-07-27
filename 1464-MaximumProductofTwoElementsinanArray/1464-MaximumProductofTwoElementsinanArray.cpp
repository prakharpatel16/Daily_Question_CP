// Last updated: 27/07/2026, 22:52:32
1class Solution {
2public:
3    int maxProduct(vector<int>& nums) {
4        sort(nums.begin(),nums.end(),greater<>());
5        int prod = (nums[0] - 1) * (nums[1] - 1);
6        return prod;
7    }
8};