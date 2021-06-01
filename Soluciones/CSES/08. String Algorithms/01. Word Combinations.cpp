#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int MAXN = 5005, ALP = 26, MOD = 1E9 + 7;
typedef long long ll;
typedef struct node *pnode;
struct node{
  bool data;
  pnode *m;
};
pnode newNode(){
  pnode aux = new node;
  aux->data = 0;
  aux->m = new pnode[ALP];
  forn(i, ALP) aux->m[i] = NULL;
  return aux;
}
struct trie{
  pnode root;
  vector<ll> dp;
  string s;
  trie(const string &t){
    int n = t.size();
    s = t;
    root = newNode();
    dp.resize(n + 1, 0);
    dp[n] = 1;
  }
  void insert(const string &s){
    pnode curr = root;
    int i = 0;
    for(char c : s){
      i = c - 'a';
      if(curr->m[i] == NULL) curr->m[i] = newNode();
      curr = curr->m[i];
    }
    curr->data = 1;
  }
  ll solve(){
    int n = s.size();
    for(int i = n - 1; i >= 0; i--){
      pnode curr = root;
      int index = 0;
      for(int j = i; j < n; j++){
        index = s[j] - 'a';
        if(curr->m[index] == NULL) break;
        curr = curr->m[index];
        if(curr->data){
          dp[i] += dp[j + 1];
          dp[i] %= MOD;
        }
      }
    }
    return dp[0];
  }
};
int main(){
  string s, t;
  cin>>s;
  trie combinations(s);
  int n;
  cin>>n;
  while(n--){
    cin>>t;
    combinations.insert(t);
  }
  cout<<combinations.solve()<<"\n";
  return 0;
}