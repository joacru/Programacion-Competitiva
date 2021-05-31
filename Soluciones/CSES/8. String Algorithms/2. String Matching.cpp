#include<bits/stdc++.h>
using namespace std;
int main(){
  string t, s;
  cin>>t>>s;
  int n = t.size(), m = s.size();
  s += '#' + t;
  n = s.size();
  vector<int> z(n);
  z[0] = n;
  int x = 0, y = 0;
  for(int i = 1; i < n; i++){
    z[i] = max(0, min(z[i - x], y - i + 1));
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
      x = i;
      y = i + z[i];
      z[i]++;
    }
  }
  int res = 0;
  for(int a : z) res += a == m;
  cout<<res<<"\n";
  return 0;
}