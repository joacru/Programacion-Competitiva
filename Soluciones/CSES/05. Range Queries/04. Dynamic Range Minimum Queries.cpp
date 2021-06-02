#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int INF = 1E9;
struct segtree{
  int n;
  vector<int> st;
  segtree(const vector<int> &a){
    int t = a.size();
    n = 2 * pow(2, ceil(log2(t))) - 1;
    st.resize(n);
    for(int i = n / 2, e = 0; i < n; i++, e++) st[i] = (e < t)? a[e] : INF;
    for(int i = n / 2 - 1; i >= 0; i--) st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
  }
  void update(int i, int v){
    i += n / 2;
    st[i] = v;
    while(i){
      i = (i - 1) / 2;
      st[i] = min(st[i * 2 + 1], st[i * 2 + 2]);
    }
  }
  int query(int ql, int qr, int sl, int sr, int i){
    if(sl >= qr || sr <= ql) return INF;
    if(sl >= ql && sr <= qr) return st[i];
    int sh = (sl + sr) / 2;
    return min(query(ql, qr, sl, sh, i * 2 + 1), query(ql, qr, sh, sr, i * 2 + 2));
  }
  int query(int ql, int qr){
    return query(ql, qr, 0, n / 2 + 1, 0);
  }
};
int main(){
  int n, q;
  cin>>n>>q;
  vector<int> a(n);
  forn(i, n) cin>>a[i];
  segtree drmq(a);
  while(q--){
    int a, b, c;
    cin>>a>>b>>c;
    b--;
    if(a == 1) drmq.update(b, c);
    else cout<<drmq.query(b, c)<<"\n";;
  }
  return 0;
}