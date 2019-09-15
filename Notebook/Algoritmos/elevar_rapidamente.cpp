ll power(ll a, ll b, ll m){ //Todo a ll para evitar errores
    return (!b)? power(a * a % m, b / 2, m) * ((b % 2)? a : 1) % m : 1;
}