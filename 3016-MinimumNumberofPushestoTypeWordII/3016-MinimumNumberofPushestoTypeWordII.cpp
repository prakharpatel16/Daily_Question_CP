// Last updated: 31/07/2026, 23:32:33
1class Solution {
2public:
3    int minimumPushes(string word) {
4        vector<int> freq(26, 0);
5        for(char c : word)
6            freq[c - 'a']++;
7        vector<pair<char, int>> arr;
8        for(int i=0;i<26;i++)
9            arr.push_back({i + 'a', freq[i]});
10        sort(arr.begin(), arr.end(), [](const auto& a, auto& b) {
11            return a.second > b.second;
12        });
13        int res = 0, n = arr.size();
14        for(int i=0;i<n;i++)
15            res += arr[i].second * (i/8 + 1);
16        return res;
17    }
18};