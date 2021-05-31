#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
int main(){
  int n;
  vector<int> coins;
  cin>>n;
  coins.resize(n);
  forn(i, n) cin>>coins[i];
  sort(coins.begin(), coins.end());
  ll nextRequired = 1;
  forn(i, n){
    if(coins[i] > nextRequired) break;
    nextRequired += coins[i];
  }
  cout<<nextRequired<<"\n";
  return 0;
}