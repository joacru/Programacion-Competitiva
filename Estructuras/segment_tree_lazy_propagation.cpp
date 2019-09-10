typedef struct segtree{
  ll *st, *lazy;
  int n;
    segtree(vector<int> datos){
        int t = datos.size(), e = 0;
        n = 2 * pow(2, ceil(log2(t))) - 1;
        st = new ll[n];
        lazy = new ll[n];
        for(int i = tam / 2; i < n; i++){
            lazy[i] = 0;
            st[i] = (e < t)? datos[e] : 0;
            e++;
        }
        for(int i = tam / 2 - 1; i >= 0; i--){
            lazy[i] = 0;
            st[i] = st[i * 2 + 1] + st[i * 2 + 2];
        }
    }
    void propagar(int sizq, int sder, int index){
        if(!lazy[index]) return;
        st[index] += (sder - sizq) * lazy[index];
        if(sizq != sder - 1){
            lazy[index * 2 + 1] += lazy[index];
            lazy[index * 2 + 2] += lazy[index];
        }
        lazy[index] = 0;
    }
    ll consultar(int cizq, int cder, int sizq, int sder, int index){
        propagar(sizq, sder, index);
        if(cizq <= sizq && cder >= sder) return st[index];
        if(sder <= cizq || sizq >= cder) return 0;
        int m = (sizq + sder) / 2;
        return consultar(cizq, cder, sizq, m, index * 2 + 1) +
                consultar(cizq, cder, m, sder, index * 2 + 2);
    }
    ll consultar(int cizq, int cder){ return consultar(cizq, cder, 0, n / 2 + 1, 0); }
    void actualizar(int uizq, int uder, int sizq, int sder, ll dif, int index){
        propagar(sizq, sder, index);
        if(uizq <= sizq && uder >= sder){
            st[index] += (sder - sizq) * dif;
            if(sizq != sder - 1){
                lazy[index * 2 + 1] += dif;
                lazy[index * 2 + 2] += dif;
            }
            return;
        }
        if(sder <= cizq || sizq >= cder) return;
        int m = (sizq + sder) / 2;
        update(uizq, uder, sizq, m, dif, index * 2 + 1);
        update(uizq, uder, m, sder, dif, index * 2 + 2);
        st[index] = st[index * 2 + 1] + st[index * 2 + 2];
    }
};
