// Last updated: 18/07/2026, 20:45:58
1class Solution {
2public:
3    string rearrangeString(string s, char x, char y) {
4        unordered_map<char, int> mpp;
5        for(auto it : s){
6            mpp[it]++;
7        }
8        string AnSWer;
9        auto jodana = [&](auto jo_haii){
10            for(char it='a';it<='z';it++){
11                if(jo_haii(it)){
12                    AnSWer.append(mpp[it], it);
13                }
14            }
15        };
16        jodana([&](char it){
17            return it == y;
18        });
19        jodana([&](char it){
20            return it != x && it != y;
21        });
22        jodana([&](char it){
23            return it == x;
24        });
25        return AnSWer;
26    }
27};