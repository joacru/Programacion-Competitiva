struct segtree{
    ll *st;
    int n;
    segtree(vector<int> datos){
        int t = datos.size(), e = 0;
        n = 2 * pow(2, ceil(log2(t))) - 1;
        st = new ll[n];
        for(int i = tam / 2; i < n; i++){
            st[i] = (e < t)? datos[e] : 0;
            e++;
        }
        for(int i = tam / 2 - 1; i >= 0; i--){
            st[i] = st[i * 2 + 1] + st[i * 2 + 2];
        }
    }
    ll consultar(int cizq, int cder, int sizq, int sder, int index){
        if(cizq <= sizq && cder >= sder) return st[index];
        if(sder <= cizq || sizq >= cder) return 0;
        int m = (sizq + sder) / 2;
        return consultar(cizq, cder, sizq, m, index * 2 + 1) +
                consultar(cizq, cder, m, sder, index * 2 + 2);
    }
    ll consultar(int cizq, int cder){ return consultar(cizq, cder, 0, n / 2 + 1, 0); }
    void actualizar(int index, int dato){
        index += n / 2;
        st[index] = dato;
        while(index != 0){
            index = (index - 1) / 2;
            st[index] = st[index * 2 + 1] + st[index * 2 + 2];
        }
    }
};