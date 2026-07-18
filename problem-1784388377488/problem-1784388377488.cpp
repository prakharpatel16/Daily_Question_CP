// Last updated: 18/07/2026, 20:56:17
1class Solution {
2public:
3    long long maximumValue(int n, int s, int m) {
4        if(n == 1){
5            return s;
6        }
7        auto nikalana = [s, m](long long kull) -> long long{
8            long long sabse_upar = kull / 2;
9            long long gaon = sabse_upar - 1;
10            return s + (sabse_upar * m) - gaon;
11        };
12        long long maxi = nikalana(n);
13        return maxi;
14    }
15};