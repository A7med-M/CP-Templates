void BellmanFord(int src) { // O(N * M) 
    int oo = 1e18;
    vector<int> dist(n, oo);
    dist[src] = 0;
    for(int i = 1; i < n; i++) {
        for(auto [u, v, w] : edges) {
            if(dist[u] != oo && dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
            }
        }
    }
    bool inf = false; // check neg cycle 
    for(auto [u, v, w] : edges) {
        if(dist[u] != oo && dist[u] + w < dist[v]) {
            inf = true;    
            break;
        }
    }
}

