#include<bits/stdc++.h>
using namespace std;
/*const int MAX = 30000000;
int serie[MAX];
int calcular(int a){
	if(serie[a] == -1) serie[a] = 1 + calcular((a % 2 == 0)? a / 2 : a * 3 + 1);
	return serie[a];
}*/
int main(){
	//memset(serie, -1, sizeof(serie));
	int a, b, ans, aux, cont;
	//serie[1] = 1;
	while(cin>>a){
		cin>>b;
		ans = 0;
		int izq = a, der = b;
		if(b < a) swap(a, b);
		for(int i = a; i <= b; i++){
			aux = i;
			cont = 0;
			while(aux != 1){
				aux = (aux % 2 == 0)? aux / 2 : aux * 3 + 1;
				cont++;
			}
			cont++;
			ans = max(ans, cont);
		}
		cout<<izq<<" "<<der<<" "<<ans<<endl;
	}
}
