int euclides(int a, int b){
    return (!b)? a : euclides(b, a % b);
}
int mcm(int a, int b){
    return a / euclides(a, b) * b;
}