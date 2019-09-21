#include<bits/stdc++.h>
using namespace std;
int main(){
	int n, m, c;
	string s, t;
	while(cin>>n){
	cin>>s>>m>>t;
	int dist[n + 1][m + 1];
	dist[0][0] = 0;
	for(int i = 1; i <= n; i++) dist[i][0] = i;
	for(int i = 1; i <= m; i++) dist[0][i] = i;
	for(int i = 1; i <= n; i++){
		for(int e = 1; e <= m; e++){
			if(s[i - 1] == t[e - 1]) c = 0;
			else c = 1;
			dist[i][e] = min(dist[i - 1][e] + 1, dist[i][e - 1] + 1);
			dist[i][e] = min(dist[i][e], dist[i - 1][e - 1] + c);
		}
	}
	cout<<dist[n][m]<<endl;
	}
}
