// Last updated: 04/08/2026, 03:08:29
1class Solution {
2public:
3    string stoneGameIII(vector<int>& stoneValue) {
4        int s1 = 0;
5        int s2 = 0;
6        int s3 = 0;
7        int total = 0;
8        for(int i=stoneValue.size()-1;i>=0;i--){
9            total += stoneValue[i];
10            int current = total - min({s1, s2, s3});
11            s3 = s2;
12            s2 = s1;
13            s1 = current;
14        }
15        int bob = total - s1;
16        if(s1 > bob){
17            return "Alice";
18        }
19        if(s1 < bob){
20            return "Bob";
21        }
22        return "Tie";
23    }
24};