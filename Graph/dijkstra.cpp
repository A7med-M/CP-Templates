void dijkstra(int src) {
    const int oo = 1e18;
    dist.assign(n + 1, oo);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    dist[src] = 0;
    pq.emplace(dist[src], src);

    while(not pq.empty()) {
        auto [c, u] = pq.top();
        pq.pop();

        if(dist[u] < c) {
            continue;
        }

        for(auto [v, w] : adj[u]) {
            if(dist[u] + w < dist[v]) {
                dist[v] = dist[u] + w;
                pq.emplace(dist[v], v);
            }
        }
    }
}

