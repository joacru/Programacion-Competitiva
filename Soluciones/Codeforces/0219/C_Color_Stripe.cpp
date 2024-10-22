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

int n, k;
string s, alp;

int getOps(bool idx){
	int ret = 0;
	forn(i,n){
		ret += s[i] != alp[idx];
		idx = !idx;
	}
	return ret;
}

void getS(bool idx){
	forn(i,n){
		s[i] = alp[idx];
		idx = !idx;
	}
}

void init(){
	for(char c = 'A'; c <= 'Z'; c++) alp.push_back(c);
}

void solve(){
	
	cin>>n>>k>>s;

	if(k == 2){
		int a = getOps(0), b = getOps(1);
		if(a < b) getS(0);
		else getS(1), a = b;
		cout<<a<<"\n"<<s<<"\n";
		return;
	}
	
	int ans = 0;
	
	forn(i,n){
		bool valid = 1;
		if(i && s[i] == s[i-1]){
			while((i && s[i] == s[i-1]) || (i < n-1 && s[i] == s[i+1])){
				s[i] = char((int(s[i])-'A'+1)%k+'A');
				valid = 0;
			}
		}
		ans += !valid;
	}
	
	cout<<ans<<"\n";
	cout<<s<<"\n";

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

	init();

    #ifdef LOCAL
    
    int tcs;
    cin>>tcs;
    while(tcs--) solve();
    
    #else
    
    solve();
    
    #endif

    return 0;
}
