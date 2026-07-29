struct DSU {
    vector<int> leader, sz;
    DSU(int n) {
        leader.assign(n + 1, 0);
        sz.assign(n + 1, 1);
        iota(leader.begin(), leader.end(), 0);
    }
    int find(int u) {
        if(leader[u] == u) return u;
        return leader[u] = find(leader[u]);
    }
    bool merge(int u, int v) {
        u = find(u), v = find(v);
        if(u == v) return false;
        if(sz[u] < sz[v]) {
            swap(u, v);
        }
        leader[v] = u, sz[u] += sz[v];
        return true;
    }
    int get_size(int u) {
        return sz[find(u)];
    }
    bool connected(int u, int v) {
        return find(u) == find(v);
    }
};

