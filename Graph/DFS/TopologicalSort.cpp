vector<int> topo_order;
bool vis[N];
void topoSort(int u) {
    vis[u] = true;
    for (int v : adj[u]) {
        if (!vis[v]) {
            topoSort(v);
        }
    }
    topo_order.push_back(u);
} // reverse(topo_order.begin(), topo_order.end());
