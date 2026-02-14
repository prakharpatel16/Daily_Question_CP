#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        vector<double> prev;
        prev.push_back((double)poured); 

        for (int i = 1; i <= query_row; i++) {
            vector<double> nxt;
            // Row 'i' has 'i+1' glasses
            int glasses_in_curr_row = i + 1; 

            for (int j = 0; j < glasses_in_curr_row; j++) {
                double flow_from_left = 0.0;
                double flow_from_right = 0.0;

                // Check top-left parent (index j-1)
                if (j - 1 >= 0) {
                    if (prev[j - 1] > 1) {
                        flow_from_left = (prev[j - 1] - 1) / 2.0;
                    }
                }

                // Check top-right parent (index j)
                if (j < prev.size()) {
                    if (prev[j] > 1) {
                        flow_from_right = (prev[j] - 1) / 2.0;
                    }
                }

                nxt.push_back(flow_from_left + flow_from_right);
            }
            prev = nxt;
        }
        return min(1.0, prev[query_glass]);
    }
};