// Last updated: 18/07/2026, 00:10:20
1class Solution {
2public:
3    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
4        int maxValue = *max_element(nums.begin(), nums.end());
5
6        vector<int> freq(maxValue + 1, 0);
7        for(int num : nums){
8            freq[num]++;
9        }
10        vector<long long> count(maxValue + 1, 0);
11        for(int gcdValue=maxValue;gcdValue>=1;gcdValue--){
12            long long total = 0;
13            for(int multiple=gcdValue;multiple<=maxValue;multiple+=gcdValue){
14                total += freq[multiple];
15            }
16            long long pairs = total * (total - 1) / 2;
17            for(
18                int multiple = 2 * gcdValue;
19                multiple <= maxValue;
20                multiple += gcdValue
21            ){
22                pairs -= count[multiple];
23            }
24            count[gcdValue] = pairs;
25        }
26        vector<long long> prefix;
27        vector<int> values;
28        long long sum = 0;
29        for(int gcdValue=1;gcdValue<=maxValue;gcdValue++){
30            if(count[gcdValue] > 0){
31                sum += count[gcdValue];
32                prefix.push_back(sum);
33                values.push_back(gcdValue);
34            }
35        }
36        vector<int> result;
37        for(long long query : queries){
38            int index = lower_bound(
39                prefix.begin(),
40                prefix.end(),
41                query + 1
42            )- prefix.begin();
43            result.push_back(values[index]);
44        }
45        return result;
46    }
47};