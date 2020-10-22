#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, a;
	cin>>n;
	vector<bool> v(n + 1);
	for(int i = 1; i < n; i++){
		cin>>a;
		v[a] = 1;
	}
	for(int i = 1; i <= n; i++) if(!v[i]) cout<<i<<"\n";
	return 0;
}
