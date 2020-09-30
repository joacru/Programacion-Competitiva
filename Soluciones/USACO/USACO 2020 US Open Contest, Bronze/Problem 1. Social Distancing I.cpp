#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int INF = 1E7;
int main(){
	ifstream cin("socdist1.in");
	ofstream cout("socdist1.out");
	int n;
	string s;
	cin>>n>>s;
	vector<int> distr(n + 1);
	distr[n] = INF;
	for(int i = n - 1; i >= 0; i--){
		if(s[i] == '1'){
			distr[i] = 0;
			continue;
		}
		distr[i] = distr[i + 1] + 1;
	}
	int bl = 0, br = n + 5, bm;
	while(br - bl > 1){
		bm = (bl + br) / 2;
		int x = -INF, p = 0;
		for(int i = 0; i < n && p < 2; i++){
			if(s[i] == '1'){
				x = i;
				continue;
			}
			if(i - x >= bm && distr[i] >= bm){
				p++;
				x = i;
			}
		}
		if(p >= 2) bl = bm;
		else br = bm;
	}
	int x = -INF;
	for(int i = 0; i < n; i++){
		if(s[i] == '0') continue;
		bl = min(bl, i - x);
		x = i;
	}
	cout<<bl<<"\n";
	return 0;
}
