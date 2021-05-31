#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int groups(const vector<int> &a, ll maxSum){
  int n = a.size(), ret = 1;
  ll sum = 0;
  forn(i, n){
    if(a[i] > maxSum) return 1E9;
    if(sum + a[i] > maxSum){
      sum = 0;
      ret++;
    }
    sum += a[i];
  }
  return ret;
}
int main(){
  int n, k;
  vector<int> a;
  cin>>n>>k;
  a.resize(n);
  forn(i, n) cin>>a[i];
  ll bl = 0, br = 1E18, bh;
  while(br - bl > 1){
    bh = (bl + br) / 2;
    if(groups(a, bh) <= k) br = bh;
    else bl = bh;
  }
  cout<<br<<"\n";
  return 0;
}