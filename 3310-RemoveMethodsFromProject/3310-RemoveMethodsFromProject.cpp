// Last updated: 06/08/2026, 03:39:46
1#include <vector>
2using namespace std;
3class Solution {
4public:
5    void dfs(int u, const vector<vector<int>>& adj, vector<bool>& isSuspicious) {
6        isSuspicious[u] = true;
7        for(int v : adj[u]){
8            if(!isSuspicious[v]){
9                dfs(v, adj, isSuspicious);
10            }
11        }
12    }
13    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
14        vector<vector<int>> adj(n);
15        for(const auto& inv : invocations){
16            adj[inv[0]].push_back(inv[1]);
17        }
18        vector<bool> isSuspicious(n, false);
19        dfs(k, adj, isSuspicious);
20        bool canRemove = true;
21        for(const auto& inv : invocations){
22            int u = inv[0], v = inv[1];
23            if(!isSuspicious[u] && isSuspicious[v]){
24                canRemove = false;
25                break;
26            }
27        }
28        vector<int> result;
29        for(int i=0;i<n;i++){
30            if(!canRemove || !isSuspicious[i]){
31                result.push_back(i);
32            }
33        }
34        return result;
35    }
36};