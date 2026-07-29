#include <bits/stdc++.h>
using namespace std;

// Dynamic Segment Tree: point update + range sum query
// Memory: ~16 bytes / node, nodes created lazily (q * log(N))
struct DynSeg {
    vector<long long> val;
    vector<int> lc, rc;          // children indices, 0 = null
    long long L, R;              // coordinate range (can be up to 1e18)

    DynSeg(long long lo, long long hi, int expectedNodes = 0) : L(lo), R(hi) {
        val.reserve(expectedNodes + 1);
        lc.reserve(expectedNodes + 1);
        rc.reserve(expectedNodes + 1);
        newNode();               // index 0 = null sentinel
        newNode();               // index 1 = root
    }

    int newNode() {
        val.push_back(0);
        lc.push_back(0);
        rc.push_back(0);
        return (int)val.size() - 1;
    }

    // add v at position p  (use assign version below if needed)
    void update(long long p, long long v) { upd(1, L, R, p, v); }
    void upd(int node, long long l, long long r, long long p, long long v) {
        if (l == r) { val[node] += v; return; }        // val[node] = v;  for assign
        long long mid = l + (r - l) / 2;
        if (p <= mid) {
            if (!lc[node]) lc[node] = newNode();
            upd(lc[node], l, mid, p, v);
        } else {
            if (!rc[node]) rc[node] = newNode();
            upd(rc[node], mid + 1, r, p, v);
        }
        val[node] = val[lc[node]] + val[rc[node]];     // val[0] == 0 دايمًا
    }

    long long query(long long ql, long long qr) { return qr < ql ? 0 : qry(1, L, R, ql, qr); }
    long long qry(int node, long long l, long long r, long long ql, long long qr) {
        if (!node || qr < l || r < ql) return 0;
        if (ql <= l && r <= qr) return val[node];
        long long mid = l + (r - l) / 2;
        return qry(lc[node], l, mid, ql, qr) + qry(rc[node], mid + 1, r, ql, qr);
    }
};
int main() {
    ios::sync_with_stdio(false); cin.tie(nullptr);
    int q; cin >> q;
    DynSeg st(1, 1e18, q * 62);   // reserve = q * log2(N)  reallocation
    while (q--) {
        int type; long long a, b; cin >> type >> a >> b;
        if (type == 1) st.update(a, b);          // add b at index a
        else cout << st.query(a, b) << '\n';     // sum [a, b]
    }
}
