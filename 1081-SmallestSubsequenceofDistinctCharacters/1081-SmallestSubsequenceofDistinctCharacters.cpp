// Last updated: 19/07/2026, 21:32:43
1class Solution {
2public:
3    string smallestSubsequence(string s) {
4        vector<int> freq(128, 0);
5        vector<bool> visited(128, false);
6        string stack;
7        for(char c : s){
8            freq[c]++;
9        }
10        for(char c : s){
11            freq[c]--;
12            if(visited[c]){
13                continue;
14            }
15            while (!stack.empty() && stack.back() > c && freq[stack.back()] > 0){
16                visited[stack.back()] = false;
17                stack.pop_back();
18            }
19            stack.push_back(c);
20            visited[c] = true;
21        }
22        return stack;
23    }
24};