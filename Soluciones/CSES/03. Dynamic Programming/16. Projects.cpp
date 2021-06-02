#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
typedef long long ll;
struct project{
  int a, b, p;
  ll dp;
  bool operator<(const project &s){
    return b < s.b; //Ordena por finalización
  }
};
int main(){
  int n;
  vector<project> projs;
  cin>>n;
  projs.push_back({0, 0, 0});
  forn(i, n){
    int a, b, p;
    cin>>a>>b>>p;
    projs.push_back({a, b, p});
  }
  sort(projs.begin(), projs.end());
  forit(i, 1, n){
    projs[i].dp = projs[i - 1].dp;
    int bl = 0, br = i, bh;
    while(br - bl > 1){
      bh = (bl + br) / 2;
      if(projs[bh].b < projs[i].a) bl = bh;
      else br = bh;
    }
    projs[i].dp = max(projs[i].dp, projs[bl].dp + projs[i].p);
  }
  cout<<projs[n].dp<<"\n";
  return 0;
}