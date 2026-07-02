void Floyd-Worshall() { // besd-0
        const int oo = 1e18;
        vector<vector<int>> dist(n, vector<int>(n, oo));

        for(int u = 0; u < n; u++) { 
            dist[u][u] = 0;
        }

        for(int i = 0; i < m; i++) { // take input directed graph
            int u, v, w;
            cin >> u >> v >> w;
            dist[u][v] = min(dist[u][v], w);
        }


        for(int k = 0; k < n; k++) { // all pairs shorts path 
            for(int u = 0; u < n; u++) {
                for(int v = 0; v < n; v++) {
                    if(dist[u][k] != oo && dist[k][v] != oo) {
                        dist[u][v] = min(dist[u][v], dist[u][k] + dist[k][v]);
                    }
                }
            }
        }

        for(int k = 0; k < n; k++) { // check negative cycle 
            if(dist[k][k] < 0) {
                for(int u = 0; u < n; u++) {
                    for(int v = 0; v < n; v++) {
                        if(dist[u][k] != oo && dist[k][v] != oo) {
                            dist[u][v] = -oo;
                        }
                    }
                }
            }
        }
        while(q--) {
            int u, v;
            cin >> u >> v;
            if(dist[u][v] == oo) {
                cout << "Impossible" << '\n';
            }
            else if(dist[u][v] == -oo) {
                cout << "-Infinity" << '\n';
            }
            else {
                cout << dist[u][v] << '\n';
            }
        }
}
