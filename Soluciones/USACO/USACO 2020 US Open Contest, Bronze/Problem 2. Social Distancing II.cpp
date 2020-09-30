#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream cin("socdist2.in");
	ofstream cout("socdist2.out");
	int n;
	cin>>n;
	int r = 1E7, res = 0;
	vector<pair<int, int> > cows(n);
	for(int i = 0; i < n; i++) cin>>cows[i].first>>cows[i].second;
	sort(cows.begin(), cows.end());
	for(int i = 1; i < n; i++){
		if(cows[i].second == cows[i - 1].second) continue;
		r = min(r, cows[i].first - cows[i - 1].first);
	}
	if(cows[0].second) res++;
	for(int i = 1; i < n; i++){
		if(cows[i].second && !cows[i - 1].second) res++;
		if(cows[i].second && cows[i - 1].second && cows[i].first - cows[i - 1].first >= r) res++;
	}
	cout<<res<<"\n";
	return 0;
}
