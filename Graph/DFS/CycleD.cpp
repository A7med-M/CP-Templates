bool hasCycleDirected(int u) {
    vis[u] = 1; 
    for (int v : adj[u]) {
        if (vis[v] == 0) {
            if (hasCycleDirected(v)) return true;
        } 
        else if (vis[v] == 1) {
            return true; 
        }
    }
    vis[u] = 2;
    return false;
}
