// Last updated: 22/07/2026, 17:07:56
1class SparseTable {
2private:
3    vector<vector<int>> st;
4
5public:
6    SparseTable(const vector<int>& data) {
7        st.push_back(data);
8        int i = 1, N = st[0].size();
9        while (2 * i <= N + 1) {
10            const auto& pre = st.back();
11            vector<int> cur;
12            for (int j = 0; j < N - 2 * i + 1; j++) {
13                cur.push_back(max(pre[j], pre[j + i]));
14            }
15            st.push_back(cur);
16            i <<= 1;
17        }
18    }
19    int query(int begin, int end) {
20        if (begin > end) {
21            return 0;
22        }
23        int len = end - begin + 1;
24        int lg = 0;
25        while ((1 << (lg + 1)) <= len) {
26            lg++;
27        }
28        return max(st[lg][begin], st[lg][end - (1 << lg) + 1]);
29    }
30};
31
32class Solution {
33public:
34    vector<int> maxActiveSectionsAfterTrade(string s,
35                                            vector<vector<int>>& queries) {
36        int n = s.length();
37        int cnt1 = count(s.begin(), s.end(), '1');
38
39        vector<int> zeroBlocks;
40        vector<int> blockLeft;
41        vector<int> blockRight;
42
43        int i = 0;
44        while (i < n) {
45            int st = i;
46            while (i < n && s[i] == s[st]) {
47                i += 1;
48            }
49            if (s[st] == '0') {
50                zeroBlocks.push_back(i - st);
51                blockLeft.push_back(st);
52                blockRight.push_back(i - 1);
53            }
54        }
55
56        int m = zeroBlocks.size();
57        if(m<2){
58            return vector<int>(queries.size(), cnt1);
59        }
60        vector<int> tmpSum(m - 1);
61        for(int i=0;i<m-1;i++){
62            tmpSum[i] = zeroBlocks[i] + zeroBlocks[i + 1];
63        }
64        SparseTable st(tmpSum);
65        vector<int> ans;
66
67        for (const auto& q : queries) {
68            int l = q[0], r = q[1];
69            int i = lower_bound(blockRight.begin(), blockRight.end(), l) -
70                    blockRight.begin();
71            int j = upper_bound(blockLeft.begin(), blockLeft.end(), r) -
72                    blockLeft.begin() - 1;
73            if (i > m - 1 || j < 0 || i >= j) {
74                ans.push_back(cnt1);
75                continue;
76            }
77
78            int firstLen = blockRight[i] - max(blockLeft[i], l)+1;
79            int lastLen = min(blockRight[j], r) - blockLeft[j]+1;
80            if (i + 1 == j) {
81                int bestGain = firstLen + lastLen;
82                ans.push_back(cnt1 + bestGain);
83                continue;
84            }
85            int val1 = firstLen + zeroBlocks[i + 1];
86            int val2 = zeroBlocks[j - 1] + lastLen;
87            int val3 = st.query(i + 1, j - 2);
88            int bestGain = max({val1, val2, val3});
89            ans.push_back(cnt1 + bestGain);
90        }
91        return ans;
92    }
93};