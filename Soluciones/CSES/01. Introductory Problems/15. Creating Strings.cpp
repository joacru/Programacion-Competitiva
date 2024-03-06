#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
#define fori(i, a, n) for(int i = a; i < n; i++)
using namespace std;
int n, final;
string s, r;
set<string> res;
void solve(int used){
	if(used == final){
		res.insert(r);
		return;
	}
	forn(i, n){
		if(used & (1<<i)) continue;
		used |= (1<<i);
		r.push_back(s[i]);
		solve(used);
		r.pop_back();
		used ^= (1<<i);
	}
	return;
}
int main(){
	cin>>s;
	n = s.size();
	final = (1<<n) - 1;
	solve(0);
	n = res.size();
	cout<<n<<"\n";
	for(set<string>::iterator it = res.begin(); it != res.end(); it++) cout<<*it<<"\n";
	return 0;
}
