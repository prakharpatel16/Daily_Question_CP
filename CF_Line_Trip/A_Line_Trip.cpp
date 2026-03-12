// Author: Prakhar Patel
// Date: 2026-03-12
// Description: Minimal C++ template for competitive programming with fast I/O

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fast;
    int t;
    cin>>t;
    while(t--){
      int n,x;
      cin>>n>>x;
      int a[n];
      for(int i=0;i<n;i++){
        cin>>a[i];
      }
      int ans = 0;
      int prev = 0;
      for(int i=0;i<n;i++){
        ans = max(ans,a[i] - prev);
        prev = a[i];
      }
      ans = max(ans,2*(x-prev));
      cout<<ans<<endl;
    }
    return 0;
}