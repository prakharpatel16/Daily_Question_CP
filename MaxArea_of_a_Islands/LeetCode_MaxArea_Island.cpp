#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void bfs(int nr, int cl, vector<vector<int>> &grid, vector<vector<int>> &vis, int &max_area, int n, int m){
        vis[nr][cl] = 1;
        vector<int> dirrow = {-1,0,1,0};
        vector<int> dircol = {0,1,0,-1};
        queue<pair<int,int>> q;
        q.push({nr,cl});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int nrow = row + dirrow[i];
                int ncol = col + dircol[i];
                if(nrow < n and nrow >=0 and ncol < m and ncol >=0 and grid[nrow][ncol] == 1 and !vis[nrow][ncol]){
                    max_area++;
                    vis[nrow][ncol] = 1;
                    q.push({nrow,ncol});
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<vector<int>> vis(grid.size(),vector<int>(grid[0].size(),0));
        int max_area = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int max_count = 1;
                if(grid[i][j] == 1 and !vis[i][j]){
                    bfs(i,j,grid,vis,max_count,n,m);
                    max_area = max(max_area,max_count);
                }
            }
        }
        return max_area;
    }
};