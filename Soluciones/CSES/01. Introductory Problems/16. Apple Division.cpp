#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
const ll INF = 1E18;
int main(){
	int n;
	ll total = 0, aux, res = INF;
	cin>>n;
	ll a[n];
	forn(i, n){
		cin>>a[i];
		total += a[i];
	}
	forn(mask, (1<<n)){
		aux = 0;
		forn(i, n){
			if(mask & (1<<i)) continue;
			aux += a[i];
		}
		res = min(res, abs(total - aux - aux));
	}
	cout<<res<<"\n";
	return 0;
}
