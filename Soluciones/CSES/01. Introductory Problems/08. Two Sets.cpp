#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n;
	cin>>n;
	ll sum = ll(n) * (n + 1) / 2;
	if(sum % 2){
		cout<<"NO\n";
		return 0;
	}
	sum /= 2;
	vector<int> fs, ss;
	for(int i = n; i > 0; i--){
		if(sum - i > 0){
			fs.push_back(i);
			sum -= i;
		} else{
			fs.push_back(sum);
			for(int j = sum + 1; j <= i; j++) ss.push_back(j);
			for(int j = 1; j < sum; j++) ss.push_back(j);
			break;
		}
	}
	cout<<"YES\n";
	n = fs.size();
	cout<<n<<"\n";
	for(int i = 0; i < n; i++) cout<<fs[i]<<" ";
	cout<<"\n";
	n = ss.size();
	cout<<n<<"\n";
	for(int i = 0; i < n; i++) cout<<ss[i]<<" ";
	cout<<"\n";
	return 0;
}
