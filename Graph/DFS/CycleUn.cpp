bool CycleUndirected(int u, int parent) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            if (hasCycleUndirected(v, u)) return true;
        } 
        else if (v != parent) { 
            return true;
        }
    }
    return false;
}
