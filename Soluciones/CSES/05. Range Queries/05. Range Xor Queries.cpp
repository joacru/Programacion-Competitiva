#include<bits/stdc++.h>
#define forit(i, a, n) for(int i = a; i <= n; i++)
using namespace std;
int main(){
  int n, q;
  cin>>n>>q;
  int add[n + 1];
  add[0] = 0;
  forit(i, 1, n){
    int x;
    cin>>x;
    add[i] = add[i - 1] ^ x;
  }
  while(q--){
    int a, b;
    cin>>a>>b;
    cout<<(add[b] ^ add[a - 1])<<"\n";
  }
  return 0;
}