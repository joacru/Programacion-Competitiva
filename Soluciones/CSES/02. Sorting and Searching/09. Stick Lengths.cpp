#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int main(){
  int n;
  ll res = 0;
  cin>>n;
  int lengths[n];
  forn(i, n) cin>>lengths[i];
  sort(lengths, lengths + n);
  forn(i, n) res += abs(lengths[n / 2] - lengths[i]);
  cout<<res<<"\n";
  return 0;
}