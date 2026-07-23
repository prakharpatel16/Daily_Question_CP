// Last updated: 23/07/2026, 20:53:11
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n = nums.size();
5        if (n == 1 || n == 2)
6            return n;
7        n |= (n >> 1);
8        n |= (n >> 2);
9        n |= (n >> 4);
10        n |= (n >> 8);
11        n |= (n >> 16);
12        return n + 1;
13    }
14};