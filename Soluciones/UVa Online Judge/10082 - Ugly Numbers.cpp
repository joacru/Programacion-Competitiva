#include<bits/stdc++.h>
#define forn(i, n) for(int i = 0; i < n; i++)
using namespace std;
char convert(char c){
	switch(c){
		case '1': return '`'; break;
		case '2': return '1'; break;
		case '3': return '2'; break;
		case '4': return '3'; break;
		case '5': return '4'; break;
		case '6': return '5'; break;
		case '7': return '6'; break;
		case '8': return '7'; break;
		case '9': return '8'; break;
		case '0': return '9'; break;
		case '-': return '0'; break;
		case '=': return '-'; break;
		case 'W': return 'Q'; break;
		case 'E': return 'W'; break;
		case 'R': return 'E'; break;
		case 'T': return 'R'; break;
		case 'Y': return 'T'; break;
		case 'U': return 'Y'; break;
		case 'I': return 'U'; break;
		case 'O': return 'I'; break;
		case 'P': return 'O'; break;
		case '[': return 'P'; break;
		case ']': return '['; break;
		case '\\': return ']'; break;
		case 'S': return 'A'; break;
		case 'D': return 'S'; break;
		case 'F': return 'D'; break;
		case 'G': return 'F'; break;
		case 'H': return 'G'; break;
		case 'J': return 'H'; break;
		case 'K': return 'J'; break;
		case 'L': return 'K'; break;
		case ';': return 'L'; break;
		case '\'': return ';'; break;
		case 'X': return 'Z'; break;
		case 'C': return 'X'; break;
		case 'V': return 'C'; break;
		case 'B': return 'V'; break;
		case 'N': return 'B'; break;
		case 'M': return 'N'; break;
		case ',': return 'M'; break;
		case '.': return '/'; break;
		case '/': return '.'; break;
		case ' ': return ' '; break;
	}
}
int main(){
	int n;
	string s;
	while(getline(cin, s)){
		n = s.size();
		forn(i, n) cout<<convert(s[i]);
		cout<<"\n";
	}
}
