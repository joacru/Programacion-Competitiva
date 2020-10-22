#include<bits/stdc++.h>
using namespace std;
int main(){
	string s;
	cin>>s;
	int n = s.size(), aux = 1, res = 0;
	s += '$';
	for(int i = 0; i < n; i++){
		if(s[i] != s[i + 1]){
			res = max(res, aux);
			aux = 1;
		} else{
			aux++;
		}
	}
	cout<<res<<"\n";
	return 0;
}
