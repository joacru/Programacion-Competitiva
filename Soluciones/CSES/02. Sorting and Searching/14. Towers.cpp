#include<bits/stdc++.h>
using namespace std;
int main(){
  int n, x;
  multiset<int> stacks;
  cin>>n;
  while(n--){
    cin>>x;
    multiset<int>::iterator it = stacks.upper_bound(x);
    if(it != stacks.end()) stacks.erase(it);
    stacks.insert(x);
  }
  cout<<stacks.size()<<"\n";
  return 0;
}