int nodo = 1, t, sig, dist[NODOS];
ll peso = 0, psig;
memset(dist, INF, sizeof(dist));
dist[1] = 0;
priority_queue<pair<ll, int> > dij;
dijk.push({-peso, nodo});
while(dij.size()){
  nodo = dij.top().second;
  peso = -dij.top().first;
  dij.pop();
  if(dist[nodo] != peso) continue;
  t = ady[nodo].size();
  forn(i, t){
    sig = ady[nodo][i].first;
    psig = peso + ady[nodo][i].second;
    if(psig < dist[sig]){
        dist[sig] = psig;
        dij.push({psig, sig});
    }
  }
}