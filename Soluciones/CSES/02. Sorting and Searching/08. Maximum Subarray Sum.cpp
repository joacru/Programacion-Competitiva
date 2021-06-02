#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 2E9;
int main(){
  int n, x, maxV = -INF;
  ll sum = 0, res = 0;
  cin>>n;
  while(n--){
    cin>>x;
    maxV = max(maxV, x);
    sum += x;
    if(sum < 0) sum = 0;
    res = max(res, sum);
  }
  if(maxV < 0) res = maxV;
  cout<<res<<"\n";
  return 0;
}