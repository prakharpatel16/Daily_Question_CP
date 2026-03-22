#include<bits/stdc++.h>
using namespace std;

int main(){

  int t;
  cin>>t;
  while(t--){
    int n;
    cin>>n;
    int a[n];
    int b[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    for(int i=0;i<n;i++){
      cin>>b[i];
    }
    vector<vector<int>> adjlist(n);
    for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
        if((i!=j) and (a[i]-b[i] >= a[j]-b[j])){
          adjlist[i].push_back(j);
        }
      }
    }
    vector<int> strong_vertices;
    for(int i=0;i<n;i++){
      vector<int> visited(n,0);
      visited[i] = 1;
      int count = 1;
      queue<int> q;
      q.push(i);
      while(!q.empty()){
        int node = q.front();
        q.pop();
        for(auto &it : adjlist[node]){
          if(!visited[it]){
            visited[it] = 1;
            q.push(it);
            count++;
          }
        }
      }
      if(count == n){
        strong_vertices.push_back(i + 1);
      }
    }
    cout<<strong_vertices.size()<<endl;
    for(auto &it : strong_vertices){
      cout<<it<<" ";
    }
    cout<<endl;
  }
  return 0;
}                       // Time Complexity ----> O(N^3)
                        // Space Complexity ----> O(N^2)


#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;

    while(t--){
        int n;
        cin>>n;

        vector<long long> a(n), b(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        long long max_value = LLONG_MIN;
        // Find maximum (a[i] - b[i])
        for(int i=0;i<n;i++){
            max_value = max(max_value, a[i] - b[i]);
        }

        vector<int> strong_vertices;
        for(int i=0;i<n;i++){
            if(a[i] - b[i] == max_value){
                strong_vertices.push_back(i + 1); // 1-based index
            }
        }
        cout<<strong_vertices.size()<<endl;
        for(int x:strong_vertices)
            cout<<x<<" ";
        cout<<endl;
    }
    return 0;
}                                              // Time Complexity ----> O(N)
                                               // Space Complexity ----> O(1)
                                               