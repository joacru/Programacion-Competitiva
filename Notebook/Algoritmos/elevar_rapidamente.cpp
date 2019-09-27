ll power(ll a, ll b, ll m){ //Todo a ll para evitar errores
	if(b == 0) return 1;
	if(b % 2){
		return (a * power(a * a % m, b / 2, m)) % m;
	} else{
		return power(a * a % m, b / 2, m) % m;
	}
}