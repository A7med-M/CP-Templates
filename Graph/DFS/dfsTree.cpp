void dfsTree(int u, int p) {
    for (int v : adj[u]) {
        if (v != p) {
            dfsTree(v, u);
        }
    }
}
