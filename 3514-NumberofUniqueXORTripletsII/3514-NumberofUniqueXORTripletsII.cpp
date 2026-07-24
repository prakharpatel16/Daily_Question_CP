// Last updated: 24/07/2026, 17:42:45
1class Solution {
2public:
3    int uniqueXorTriplets(vector<int>& nums) {
4        int n=nums.size();
5        unordered_set<int> l1, l2;
6        unordered_set<int> st;
7        for(int i=0;i<n;i++){
8            if(l1.contains(nums[i])) continue;
9            l1.insert(nums[i]);
10            for(int j=i;j<n;j++){
11                int val=nums[i] xor nums[j];
12                if(l2.contains(val)) continue;
13                l2.insert(val);
14                for(int k=j;k<n;k++){
15                    st.insert(nums[i] xor nums[j] xor nums[k]);
16                }
17            }
18        }
19        return st.size();
20    }
21};