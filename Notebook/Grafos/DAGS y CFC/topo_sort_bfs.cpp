int entrantes[NODOS + 1], actual, t, sig;
memset(entrantes, 0, sizeof(entrantes));
//Cargar grafo aumentando entrantes[i] cada vez que llegue una arista al nodo i
vector<int> toposort;
queue<int> topo;
forit(i, 1, n){
    if(!entrantes[i]){
        topo.push(i);
    }
}
while(q.size()){
    actual = topo.front();
    topo.pop();
    toposort.push_back(actual);
    t = grafo[actual].size();
    forn(i, t){
        sig = grafo[actual][i];
        entrantes[sig]--;
        if(!entrantes[sig]){
            topo.push(sig);
        }
    }
}
if(toposort.size() == n){
    cout<<toposort[0];
    fori(i, 1, n) cout<<" "<<toposort[i];
}
cout<<endl;