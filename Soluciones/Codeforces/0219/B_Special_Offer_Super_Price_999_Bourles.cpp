#include <bits/stdc++.h>

#define  DBG(x      ) cerr<<#x<<" = "<<(x)<<endl
#define DBGY(x      ) cerr<<#x<<" = "<<(x)<<", ";
#define DBG2(x,y    ) DBGY(x) DBG(y);
#define DBG3(x,y,z  ) DBGY(x) DBGY(y) DBG(z)
#define DBG4(x,y,z,w) DBGY(x) DBGY(y) DBGY(z) DBG(w)
#define RAYA cerr<<" ============================== "<<endl

#define forn(i,n) for(int i = 0; i < int(n); i++)
#define fort(i,n) for(int i = 0; i <= int(n); i++)
#define fori(i,a,n) for(int i = a; i < int(n); i++)
#define forit(i,a,n) for(int i = a; i <= int(n); i++)

#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()

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

template<typename S, typename T>
ostream & operator<<(ostream &os, const pair<S, T> &p){
	os<<"("<<p.first<<", "<<p.second<<")";
	return os;
}

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

void solve(){
	
	ll p, d;
	cin>>p>>d;
	
	for(ll t = 1; t <= ll(1e17); t *= 10){
		ll x = (p / t) % 10;
		if(x != 9){
			if(t*(x+1) > d){
				cout<<p<<"\n";
				return;
			}
			d -= t*(x+1);
			p -= t*(x+1);
		}
	}
	
	cout<<p<<"\n";

}

int main(){

	cin.tie(NULL);
	ios::sync_with_stdio(0);

    #ifdef LOCAL
        freopen("input.in", "r", stdin);
    #else
        //~ freopen("input.in", "r", stdin);
        //~ freopen("output.out", "w", stdout);
    #endif

    #ifdef LOCAL
    
    int tcs;
    cin>>tcs;
    while(tcs--) solve();
    
    #else
    
    solve();
    
    #endif

    return 0;
}
