#include<bits/stdc++.h>
#define sp system("pause")
using namespace std;
typedef long long ll;
int main(){
	int tc;
	cin>>tc;
	while(tc--){
		ll n, a = 9;
		int d = 1, b = 1; //Cantidad de d�gitos - Cantidad de d�gitos
		string s = ""; //N�mero a encontrar
		cin>>n;
		while(a * d < n){ //Detectar la cantidad de digitos que tiene
			n -= a * d;
			a *= 10;
			d++;
		}
		n--; //Para contar los desplazamientos		
		a /= 9; //Es la cantidad necesaria para desplazar (es 10 a la (cantidad de d�gitos - 1))
		//cout<<"Empieza el trabajo sucio "<<d<<" "<<a<<"\n";
		for(int c = d; c > 0; c--, a /= 10){ //c marca el d�gito actual
			while(a * d <= n){
				n -= a * d;
				b++;
				//cout<<n<<" "<<a<<" "<<c<<" "<<d<<" "<<b<<"\n"; sp;
			}
			s += char(b + '0');
			b = 0;
		}
		//cout<<s<<"\n";
		cout<<s[n]<<"\n";
	}
	return 0;
}
