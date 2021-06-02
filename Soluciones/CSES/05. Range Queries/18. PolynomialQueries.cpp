#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
struct segtree{
  int n;
  vector<ll> st, lazyOne, lazyTwo;
  segtree(const vector<int> &a){
    int t = a.size();
    n = 2 * pow(2, ceil(log2(t))) - 1;
    st.resize(n);
    lazyOne.resize(n);
    lazyTwo.resize(n);
    for(int i = n / 2, e = 0; e < t; i++, e++) st[i] = a[e];
    for(int i = n / 2 - 1; i >= 0; i--) st[i] = st[i * 2 + 1] + st[i * 2 + 2];
  }
  void push(int sl, int sr, int i){
    //cout<<"St "<<i<<": "<<st[i];
    st[i] += (sr - sl) * lazyOne[i];
    st[i] += lazyTwo[i] * (sr - sl) * (sr - sl + 1) / 2;
    //out<<" LazyOne "<<i<<": "<<lazyOne[i]<<" LazyTwo "<<i<<": "<<lazyTwo[i]<<" St "<<i<<": "<<st[i]<<"\n";
    if(sr - sl > 1){
      lazyOne[i * 2 + 1] += lazyOne[i];
      lazyOne[i * 2 + 2] += lazyOne[i];

      lazyTwo[i * 2 + 1] += lazyTwo[i];
      lazyOne[i * 2 + 2] += (sr - (sl + sr) / 2) * lazyTwo[i];
      lazyTwo[i * 2 + 2] += lazyTwo[i];
    }
    lazyOne[i] = 0;
    lazyTwo[i] = 0;
  }
  void update(int ql, int qr, int sl, int sr, int i){
    push(sl, sr, i);
    if(sl >= qr || sr <= ql) return;
    if(sl >= ql && sr <= qr){
      lazyOne[i] += sl - ql; //Creo que con eso basta
      lazyTwo[i]++; //Creo que sí o sí hay que hacer una escalerita
      push(sl, sr, i);
      return;
    }
    int sh = (sl + sr) / 2;
    update(ql, qr, sl, sh, i * 2 + 1);
    update(ql, qr, sh, sr, i * 2 + 2);
    st[i] = st[i * 2 + 1] + st[i * 2 + 2];
  }
  void update(int ql, int qr){
    update(ql, qr, 0, n / 2 + 1, 0);
  }
  ll query(int ql, int qr, int sl, int sr, int i){
    push(sl, sr, i);
    if(sl >= qr || sr <= ql) return 0;
    if(sl >= ql && sr <= qr) return st[i];
    int sh = (sl + sr) / 2;
    return query(ql, qr, sl, sh, i * 2 + 1) + query(ql, qr, sh, sr, i * 2 + 2);
  }
  ll query(int ql, int qr){
    return query(ql, qr, 0, n / 2 + 1, 0);
  }
};
int main(){
  int n, q;
  cin>>n>>q;
  vector<int> a(n);
  forn(i, n) cin>>a[i];
  segtree poque(a);
  while(q--){
    int a, b, c;
    cin>>a>>b>>c;
    b--;
    if(a == 1) poque.update(b, c);
    else cout<<poque.query(b, c)<<"\n";
  }
  return 0;
}