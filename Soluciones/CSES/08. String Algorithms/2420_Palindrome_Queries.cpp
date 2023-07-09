#include <iostream>
#include <assert.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define  DBG(x         ) cerr<<#x<<" = "<<(x)<<endl
#define DBG2(x, y      ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<endl
#define DBG3(x, y, z   ) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<endl
#define DBG4(x, y, z, w) cerr<<#x<<" = "<<(x)<<", "<<#y<<" = "<<(y)<<", "<<#z<<" = "<<(z)<<", "<<#w<<" = "<<(w)<<endl
#define RAYA cerr<<" =============== "<<endl

#define forn(i, n) for(int i = 0; i < int(n); i++)
#define fort(i, n) for(int i = 0; i <= int(n); i++)
#define fori(i, a, n) for(int i = a; i < int(n); i++)
#define forit(i, a, n) for(int i = a; i <= int(n); i++)

using namespace std;

template<typename T>
ostream & operator<<(ostream &os, const vector<T> &v){
    os<<"[";
    forn(i, (int) v.size()){
        if(i) os<<", ";
        os<<v[i];
    }
    os<<"]";
    return os;
}

typedef long long ll;
typedef long double ld;

const int MAXN = 2E5 + 5, A = 911382323, MOD = 972663749;

ll p[MAXN];

void init(){
	p[0] = 1;
	fori(i, 1, MAXN){
		p[i] = p[i - 1] * A;
		p[i] %= MOD;
	}
}

int merge(ll left, ll right, int size){
	ll ret = p[size / 2] * left;
	ret += right;
	ret %= MOD;
	return int(ret);
}

struct segtree{
	int n;
	vector<ll> st;
	segtree(const string &s){
		int t = s.size();
		n = 2 * (int) pow(2, ceil(log2(t))) - 1;
		st.resize(n);
		forn(i, t) update(i, s[i]);
	}
	void update(int i, char c){
		int s = 1;
		i += n / 2;
		st[i] = c;
		while(i){
			s *= 2;
			i = (i - 1) / 2;
			st[i] = merge(st[i * 2 + 1], st[i * 2 + 2], s);
		}
	}
	int query(int ql, int qr, int sl, int sr, int i){
		if(sl >= qr || sr <= ql) return 0;
		//DBG4(ql, qr, sl, sr);
		if(sl >= ql && sr <= qr) return int(st[i] * p[qr - sr] % MOD);
		int sh = (sl + sr) / 2;
		return (query(ql, qr, sl, sh, i * 2 + 1) + query(ql, qr, sh, sr, i * 2 + 2)) % MOD;
	}
	int query(int ql, int qr){
		return query(ql, qr, 0, n / 2 + 1, 0);
	}
};

int main(){

    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
        //freopen("cows.in", "r", stdin);
        //freopen("cows.out", "w", stdout);
    #endif

	init();

    int n, q;
    cin>>n>>q;
    string s;
    cin>>s;
    
    segtree stf(s);
    reverse(s.begin(), s.end());
    segtree sts(s);
    
    while(q--){
		int t;
		cin>>t;
		if(t == 1){
			int k;
			char x;
			cin>>k>>x;
			stf.update(k - 1, x);
			sts.update(n - k, x);
		} else{
			int l, r;
			cin>>l>>r;
			int fst = stf.query(l - 1, r);
			int snd = sts.query(n - r, n - l + 1);
			if(fst == snd) cout<<"YES\n";
			else cout<<"NO\n";
		}
	}

    return 0;
}
