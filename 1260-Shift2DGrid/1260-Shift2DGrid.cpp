// Last updated: 20/07/2026, 20:46:16
1class Solution {
2public:
3    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
4        int m=grid.size();
5        int n=grid[0].size();
6        int total=m*n;
7        k%=total;
8        vector<vector<int>>ans(m,vector<int>(n));
9        for(int i=0;i<m;i++){
10            for(int j=0;j<n;j++){
11                int oldIndex=i*n+j;
12                int newIndex=(oldIndex+k)%total;
13                ans[newIndex/n][newIndex%n]=grid[i][j];
14            }
15        }
16        return ans;
17    }
18};