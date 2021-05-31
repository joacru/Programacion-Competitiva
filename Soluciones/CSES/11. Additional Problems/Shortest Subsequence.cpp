#include<bits/stdc++.h>
using namespace std;
int main(){
  string s, res = "", dna = "ACGT";
  cin>>s;
  int used = 15;
  for(char c : s){
    int i = 0;
    if(c == 'A') i = 0;
    else if(c == 'C') i = 1;
    else if(c == 'G') i = 2;
    else if(c == 'T') i = 3;
    if(used & (1<<i)) used ^= (1<<i);
    if(!used){
      res += c;
      used = 15;
    }
  }
  for(int i = 0; i < 4; i++){
    if(used & (1<<i)){
      res += dna[i];
      break;
    }
  }
  cout<<res<<"\n";
  return 0;
}