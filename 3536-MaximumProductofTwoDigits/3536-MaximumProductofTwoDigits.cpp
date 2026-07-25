// Last updated: 25/07/2026, 14:35:07
1class Solution {
2public:
3    int maxProduct(int n) {
4        string s = to_string(n);
5        sort(s.begin(), s.end());
6        int d1 = s[s.size() - 2] - '0';
7        int d2 = s[s.size() - 1] - '0';
8        return d1 * d2;
9    }
10};