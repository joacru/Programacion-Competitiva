#include<bits/stdc++.h>
using namespace std;
int  main(){
	int n;
	cin>>n;
	if(n > 1 && n < 4){
		cout<<"NO SOLUTION"<<endl;
		return 0;
	}
	for(int i = 2; i <= n; i += 2) cout<<i<<" ";
	for(int i = 1; i <= n; i += 2) cout<<i<<" ";
	cout<<endl;
	return 0;
}
