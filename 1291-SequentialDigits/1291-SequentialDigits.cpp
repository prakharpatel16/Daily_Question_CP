// Last updated: 13/07/2026, 14:47:14
1class Solution {
2public:
3    vector<int> sequentialDigits(int low, int high) {
4        vector<int> digits;
5        for(int i=1;i<=9;i++){
6            int first_digit = i;
7            for(int j=i+1;j<=9;j++){
8                first_digit = (first_digit * 10) + j;
9                if(low <= first_digit and high >= first_digit){
10                    digits.push_back(first_digit);
11                }
12            }
13        }
14        sort(digits.begin(),digits.end());
15        return digits;
16    }
17};
18
19// 10000 - 200000  = 12345, 23456, 34567, 45678, 56789
20// 100 - 3000 = 123, 234, 345, 456, 567, 678, 789, 
21
22// 8  Transition ----> 1 -> 2
23// 7  Transition ----> 2 -> 3
24// 6  Transition ----> 3 -> 4
25// 5  Transition ----> 4 -> 5
26
27// (low_count - 1) - (high_count - 1) == 0    ----> 
28// (low_count - 1) - (high_count - 1) > 0 ----> 
29
30// without zero
31// 10000 - 16000 ----> 1 
32// 20000 - 50000 ----> 23456, 34567, 45678