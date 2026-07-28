// Last updated: 29/07/2026, 03:38:15
1class Solution {
2public:
3    string smallestPalindrome(string s) {
4        int n=s.length();
5        int pivot=n/2;
6        sort(s.begin(),s.begin()+pivot);
7        sort(s.end()-pivot,s.end());
8        reverse(s.end()-pivot,s.end());
9        return s;
10    }
11};