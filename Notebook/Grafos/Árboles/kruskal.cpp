int main(){
	arista ari;
	vector<arista> es;
	sort(es.begin(), es.end());
	m = es.size();
	uf kruskal; kruskal.init();
	forn(i, m){
		ari = es[i];
		a = ari.a; b = ari.b; l = ari.l;
		if(kruskal.unir(a, b)) res += l;
	}
	cout<<res<<endl;
}