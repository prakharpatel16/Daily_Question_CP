// Last updated: 18/07/2026, 21:29:10
1class Solution {
2public:
3    int minAdjacentSwaps(vector<int>& nums, int a, int b) {
4        const auto jt = nums.size();
5        const long long seemet = 1'000'000'007LL;
6        struct time{
7            long long pehlaa = 0;
8            long long dusraa = 0;
9            long long badlle = 0;
10        } haii;
11        auto it = [&](const int st){
12            if(st < a){
13                haii.badlle = (haii.badlle + haii.pehlaa + haii.dusraa) % seemet;
14            }
15            else if(st <= b){
16                haii.badlle = (haii.badlle + haii.dusraa) % seemet;
17                haii.pehlaa++;
18            }
19            else{
20                haii.dusraa++;
21            }
22        };
23        std::for_each(nums.begin(),nums.begin() + jt, it);
24        return static_cast<int>(haii.badlle);
25    }
26};