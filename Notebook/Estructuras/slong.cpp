
typedef string slong;
slong tslong(int a){
    if(a == 0) return "0";
    slong c = "";
    int d = 1;
    char f;
    while(d <= a) d *= 10;
    for(d /= 10; d >= 1; d /= 10){
        f = (a / 10) + '0';
        c += f;
        a %= d;
    }
    return c;
}
bool operator < (slong a, slong b){
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    int i;
    for(i = 0; a[i] == b[i]; i++);
    if(i == a.size()) return false;
    if(a[i] < b[i]) return true;
    return false;
}
bool operator <= (slong a, slong b){
    if(a.size() < b.size()) return true;
    if(a.size() > b.size()) return false;
    int i;
    for(i = 0; a[i] == b[i]; i++);
    if(i == a.size()) return true;
    if(a[i] < b[i]) return true;
    return false;
}
slong operator + (slong a, slong b){
    if(a == "0" && b == "0") return "0";
    if(a == "0") return b;
    if(b == "0") return a;
    char f;
    slong c = "";
    int ai = a.size() - 1, bi = b.size() - 1, va, vb, r = 0;
    for(int i = max(ai, bi); i > -1; i--){
        if(ai > -1) r += a[ai] - '0';
        if(bi > -1) r += b[bi] - '0';
        f = (r % 10) + '0';
        c += f;
        r /= 10;
        ai--;
        bi--;
    }
    f = r + '0';
    if(r != 0) c += f;
    reverse(c.begin(), c.end());
    return c;
}
slong operator ++ (slong &a){
    slong b = "1";
    a = a + b;
    return a;
}
slong operator * (slong a, slong b){
    slong c = "0", d = "1";
    for(slong i = tslong(0); i < b; i = i + d) c = c + a;
    return c;
}