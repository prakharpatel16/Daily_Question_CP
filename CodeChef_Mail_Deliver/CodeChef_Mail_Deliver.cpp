// Question Link : https://www.codechef.com/SAMPP/problems/MAIL_DELIVER

#include<bits/stdc++.h>
using namespace std;

int main(){
    
    int t;
    cin>>t;
    while(t--){
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> xi(n);
    vector<int> di(n);
    for(int i=0;i<k;i++){
        cin>>xi[i];
    }
    for(int i=0;i<k;i++){
        cin>>di[i];
    }
    vector<vector<int>> adjlist(n+1);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjlist[u].push_back(v);
        adjlist[v].push_back(u);
    }
    queue<pair<int,int>> q;
    vector<int> vis(n+1,-1);
    for(int i=0;i<k;i++){
        int node = xi[i];
        int dist = di[i] - 1;
        if(vis[node] < dist){
            vis[node] = dist;
            q.push({node,dist});
        }
    }
    while(!q.empty()){
        int node = q.front().first;
        int dist = q.front().second;
        q.pop();
        if(dist == 0){
            continue;
        }
        for(auto &it : adjlist[node]){
            if(vis[it] < dist - 1){
                vis[it] = dist - 1;
                q.push({it,dist-1});
            }
        }
    }
    bool ok = true;
    for(int i=1;i<=n;i++){
        if(vis[i] == -1){
            ok = false;
            break;
        }
    }
    if(ok){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }
    }
    return 0;
}                      // Time Complexity ----> O(N+M)
                       // Space Complexity ----> O(N+M)