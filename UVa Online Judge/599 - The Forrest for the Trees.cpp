#include<bits/stdc++.h>
using namespace std;
int main(){
	int T, a, b, n, bellotas, arboles, t;
	string s;
	bool usar[26], vis[26];
	cin>>T;
	while(T--){
		bellotas = 0;
		arboles = 0;
		vector<int> ady[26];
		memset(usar, false, sizeof(usar));
		memset(vis, false, sizeof(vis));
		cin>>s;
		while(s[0] != '*'){
			a = s[1] - 'A';
			b = s[3] - 'A';
			ady[a].push_back(b);
			ady[b].push_back(a);
			usar[a] = true;
			usar[b] = true;
			cin>>s;
		}
		cin>>s;
		n = s.size();
		for(int i = 0; i < n; i += 2){
			a = s[i] - 'A';
			if(!usar[a]) bellotas++;
		}
		queue<int> bfs;
		for(int i = 0; i < 26; i++){
			if(usar[i] && !vis[i]){
				vis[i] = true;
				arboles++;
				bfs.push(i);
				while(bfs.size()){
					a = bfs.front();
					bfs.pop();
					t = ady[a].size();
					for(int e = 0; e < t; e++){
						b = ady[a][e];
						if(vis[b]) continue;
						vis[b] = true;
						bfs.push(b);
					}
				}
			}
		}
		cout<<"There are "<<arboles<<" tree(s) and "<<bellotas<<" acorn(s).\n";
	}
}
