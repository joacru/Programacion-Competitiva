#include<bits/stdc++.h>
#define sp system("pause")
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef map<int, int> mii;
const int MAXN = 22, MAXS = 1E6 + 3, MOD = 1E6 + 3;
int criba[MOD];
ll r[MAXS];
ll magic(int n){
	if(n == 0) return 0;
	if(n == 1) return 1;
	ll ret = 1;
	mii f;
	while(n > 1){
		f[criba[n]]++;
		n /= criba[n];
	}
	if(f.size() == 1){
		int x = f.begin()->first, y = f.begin()->second;
		ll z = 1;
		forn(i, y) z *= x, ret += (z * z);
		return ret;
	}
	for(mii::iterator it = f.begin(); it != f.end(); it++){
		int e = 0, x = it->first, y = it->second;
		ll z = 1;
		forn(i, y) z *= x;
		ret *= r[z];
	}
	return ret;
}
int main(){
	forn(i, MOD) criba[i] = i;
	for(int i = 4; i < MOD; i += 2) criba[i] = 2;
	for(int i = 3; i <= sqrt(MOD); i += 2){
		if(criba[i] != i) continue;
		for(int e = i * i; e < MOD; e += (i * 2)) criba[e] = i;
	}
	forn(i, MAXS) r[i] = magic(i);
	int p[MAXS];
	int n, q, k, x;
	vector<int> s;
	scanf("%d%d", &n, &q);
	ll dp[1<<n];
	forn(i, n){
		scanf("%d", &x);
		s.push_back(x);
		p[x] = i;
	}
	forn(mask, (1<<n)){
		ll m = 1;
		forn(i, n){
			if(mask & (1<<i)) continue;
			m *= s[i];
			m %= MOD;
		}
		dp[mask] = r[m] - (m * m);
	}
	forn(i, n){
		for(int mask = (1<<n) - 1; mask >= 0; mask--){
			if(mask & (1<<i)) dp[mask] += dp[mask ^ (1<<i)];
		}
	}
	while(q--){
		int mask = (1<<n) - 1;
		scanf("%d", &k);
		forn(i, k){
			scanf(" %d", &x);
			mask ^= (1<<p[x]);
		}
		printf("%lld ", dp[mask]);
	}
	printf("\n");
	return 0;
}
