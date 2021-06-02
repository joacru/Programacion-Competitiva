#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
typedef long long ll;
int main(){
  int n;
  ll res = 0;
  cin>>n;
  vector<int> a;
  int nse[n + 2];
  a.push_back(0);
  forn(i, n){
    int x;
    cin>>x;
    a.push_back(x);
  }
  a.push_back(0);
  stack<int> se;
  se.push(0);
  forit(i, 1, n){
    while(a[se.top()] >= a[i]) se.pop();
    nse[i] = se.top();
    se.push(i);
  }
  while(se.size()) se.pop();
  se.push(n + 1);
  forn(i, n){
    while(a[se.top()] >= a[n - i]) se.pop();
    res = max(res, ll(se.top() - nse[n - i] - 1) * a[n - i]);
    se.push(n - i);
  }
  cout<<res<<"\n";
  return 0;
}