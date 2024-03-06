#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
const int ALP = 26;
int main(){
	int n, c = -1, r = 0;
	string s;
	vector<int> l[ALP];
	cin>>s;
	n = s.size();
	char res[n];
	forn(i, n) l[s[i] - 'A'].push_back(i);
	forn(i, n){
		if(s[i] == '-') continue;
		int x = l[s[i] - 'A'].back();
		l[s[i] - 'A'].pop_back();
		if(x == i){
			if(c != -1){
				cout<<"NO SOLUTION\n";
				return 0;
			}
			c = r;
			res[n / 2] = s[i];
			continue;
		}
		res[r++] = s[i];
		res[n - r] = s[x];
		s[x] = '-';
	}
	forn(i, n) cout<<res[i]; cout<<"\n";
	return 0;
}
