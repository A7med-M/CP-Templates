int color[N]; 
bool isBipartite(int u, int c) {
    color[u] = c;
    for (int v : adj[u]) {
        if (color[v] == -1) {
            if (!isBipartite(v, 1 - c)) return false;
        } 
        else if (color[v] == color[u]) {
            return false;
        }
    }
    return true;
}
