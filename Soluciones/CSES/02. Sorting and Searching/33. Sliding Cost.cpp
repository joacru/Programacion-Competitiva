#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const int MAXN = 2E5 + 5;
struct segtree{
  int n;
  vector<int> stCnt;
  vector<ll> stSum;
  map<int, int> valPos;
  vector<int> posVal;
  segtree(const vector<int> &a){
    int i = 0;
    for(int x : a) valPos[x];
    for(map<int, int>::iterator it = valPos.begin(); it != valPos.end(); it++){
      it->second = i++;
      posVal.push_back(it->first);
    }
    n = 2 * pow(2, ceil(log2(MAXN))) - 1;
    stCnt.resize(n);
    stSum.resize(n);
  }
  void update(int x){
    int i = valPos[abs(x)] + n / 2;
    stCnt[i] += (x > 0)? +1 : -1;
    stSum[i] += x;
    while(i){
      i = (i - 1) / 2;
      stCnt[i] = stCnt[i * 2 + 1] + stCnt[i * 2 + 2];
      stSum[i] = stSum[i * 2 + 1] + stSum[i * 2 + 2];
    }
  }
  pair<int, ll> query(int ql, int qr, int sl, int sr, int i){
    if(sl >= qr || sr <= ql) return {0, 0};
    if(sl >= ql && sr <= qr) return {stCnt[i], stSum[i]};
    int sh = (sl + sr) / 2;
    pair<int, ll> left = query(ql, qr, sl, sh, i * 2 + 1), right = query(ql, qr, sh, sr, i * 2 + 2);
    return {left.first + right.first, left.second + right.second};
  }
  ll query(){
    //Encontrar primero la posición correcta
    int k = stCnt[0] / 2, i = 0;
    while(i < n / 2){
      if(stCnt[i * 2 + 1] > k) i = i * 2 + 1;
      else k -= stCnt[i * 2 + 1], i = i * 2 + 2;
      //cout<<"("<<i<<" "<<stCnt[i]<<") ";
    } //cout<<"\n"; sp;
    i -= n / 2;
    ll median = posVal[i];
    //cout<<stCnt[0]<<" "<<k<<" "<<i<<" "<<median<<"\n";
    pair<int, ll> left = query(0, i, 0, n / 2 + 1, 0), right = query(i, n / 2 + 1, 0, n / 2 + 1, 0);
    //cout<<left.second<<" "<<left.first<<" "<<right.second<<" "<<right.first<<"\n"; sp;
    return -left.second + median * left.first + right.second - median * right.first;
  }
};
int main(){
  int n, k;
  cin>>n>>k;
  vector<int> a(n);
  forn(i, n) cin>>a[i];
  segtree sliding(a);
  forn(i, k) sliding.update(a[i]);
  cout<<sliding.query();
  for(int i = k; i < n; i++){
    sliding.update(-a[i - k]);
    sliding.update(a[i]);
    cout<<" "<<sliding.query();
  }
  cout<<"\n";
  return 0;
}