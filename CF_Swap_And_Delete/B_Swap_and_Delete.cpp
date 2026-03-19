// Author: Prakhar Patel
// Date: 2026-03-18
// Description: Minimal C++ template for competitive programming with fast I/O

#include <bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);

int main() {
    fast;
    int t;
    cin>>t;
    while(t--){
      string s;
      cin>>s;
      int count_0 = 0;
      int count_1 = 0;
      for(int i=0;i<s.size();i++){
        if(s[i] == '0'){
          count_0++;
        }
        else{
          count_1++;
        }
      }
      int f_length = 0;
      for(int i=0;i<s.size();i++){
        if(s[i] == '0' and count_1 > 0){
          count_1--;
          f_length++;
        }
        else if(s[i] == '1' and count_0 > 0){
          count_0--;
          f_length++;
        }
        else{
          break;
        }
    }
    cout<<s.size() - f_length<<endl;
    }
    return 0;
}                        // Time Complexity ---- O(N)
                         // Space Complexity ---- O(1)
