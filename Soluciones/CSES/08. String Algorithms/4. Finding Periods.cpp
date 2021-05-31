#include<bits/stdc++.h>
using namespace std;
vector<int> z;
int getGoodLimit(int limit, int size){
  int div = (limit + size - 1) / size;
  return div * size;
}
bool check(int rl, int ps){ //Limite de la derecha y Tamaño del periodo
  if(rl == ps) return 1;
  int hl = getGoodLimit(rl / 2, ps);
  if(z[hl] != z.size() - hl) return 0;
  return check(hl, ps);
}
int main(){
  string s;
  cin>>s;
  int n = s.size(), x = 0, y = 0;
  z.resize(n);
  z[0] = n;
  for(int i = 1; i < n; i++){
    z[i] = max(0, min(z[i - x], y - i + 1));
    while(i + z[i] < n && s[z[i]] == s[i + z[i]]){
      x = i;
      y = x + z[i];
      z[i]++;
    }
  }
  vector<int> res;
  for(int i = 1; i <= n; i++){
    if(check(getGoodLimit(n, i), i)) res.push_back(i);
  }
  for(int a : res) cout<<a<<" ";
  cout<<"\n";
  return 0;
}