// Last updated: 15/07/2026, 13:22:06
1class Solution {
2public:
3    int gcdOfOddEvenSums(int n) {
4        int sum_odd = 0;
5        int sum_even = 0;
6        int orgi = n;
7        for(int i=1;i<n*n;i+=2){
8            if(orgi == 0){
9                break;
10            }
11            sum_odd += i;
12            orgi--;
13        }
14        orgi = n;
15        for(int i=2;i<n*n;i+=2){
16            if(orgi == 0){
17                break;
18            }
19            sum_even += i;
20            orgi--;
21        }
22        if(sum_odd == 0 or sum_even == 0){
23            return 1;
24        }
25        return __gcd(sum_odd,sum_even);
26    }
27};