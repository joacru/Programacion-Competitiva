#include<bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin>>s;
  int n = s.size(), x = 0, y = 0;
  vector<int> z(n);
  for(int i = 1; i < n; i++){
    z[i] = max(0, min(z[i - x], y - i + 1));
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
      x = i;
      y = i + z[i];
      z[i]++;
    }
  }
  vector<int> res;
  for(int i = 1; i < n; i++) if(z[n - i] == i) res.push_back(i);
  for(int a : res) cout<<a<<" ";
  cout<<"\n"; 
  return 0;
}