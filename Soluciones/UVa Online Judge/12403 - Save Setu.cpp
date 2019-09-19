#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, cuenta = 0, d;
	string op;
	cin>>T;
	while(T--){
		cin>>op;
		if(op == "donate"){
			cin>>d;
			cuenta += d;
		} else if(op == "report"){
			cout<<cuenta<<endl;
		}
	}
}
