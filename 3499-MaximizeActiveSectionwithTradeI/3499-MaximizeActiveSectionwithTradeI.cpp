// Last updated: 22/07/2026, 01:51:25
1class Solution {
2public:
3    int maxActiveSectionsAfterTrade(string s) {
4        vector<int> zeros;
5        int run = 0;
6        for(char c : s)
7            if (c == '0') ++run;
8            else if (run) zeros.push_back(exchange(run, 0));
9        if(run) zeros.push_back(run);
10        int maxzeros = 0;
11        for(int i=1;i<zeros.size();++i)
12            maxzeros = max(maxzeros, zeros[i - 1] + zeros[i]);
13        return ranges::count(s, '1') + maxzeros;
14    }
15};