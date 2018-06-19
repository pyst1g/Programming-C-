//prim(ノード数、edge[頂点名][距離、行先の頂点])
ll prim(int N, vector<vector<pii >> edge) {
    priority_queue<pii, vector<pii >, greater<pii>> pq;
    vb used(N, false);
    pq.push(pii(0, 0));
    ll total = 0;
    while (!pq.empty()) {
        int dis, t;
        tie(dis, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        total += dis;
        for (auto e: edge[t]) {
            if (!used[e.second]) pq.push(e);
        }
    }
    return total;
}
