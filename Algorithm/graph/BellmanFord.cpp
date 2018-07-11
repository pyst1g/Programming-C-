//BellmanFord(開始ノード、ノード数、エッジ数、頂点名、行先の頂点、距離、返り値距離、返り値負閉路(trueだと閉路有))
template<typename T>
void BellmanFord2(int s, int V, int E, vector<int> from, vector<int> to, vector<T> d, vector<T> &dist,
                  vector<bool> &negative) {
    if (typeid(T) == typeid(int)) dist = vector<T>(V, INF);
    else dist = vector<T>(V, LONG_LONG_MAX / 4);
    dist[s] = 0;
    bool ischange;
    int cnt = 0;
    vector<bool> used;

    rep(i, V - 1) {
        ischange = false;
        rep(j, E) {
            if (dist[from[j]] + d[j] < dist[to[j]]) {
                ischange = true;
                dist[to[j]] = dist[from[j]] + d[j];
            }
        }
        if (!ischange) break;
    }

    negative = vector<bool>(V, false);

    rep(i, V) {
        ischange = false;
        rep(j, E) {
            if (dist[from[j]] + d[j] < dist[to[j]]) {
                ischange = true;
                dist[to[j]] = dist[from[j]] + d[j];
                negative[to[j]] = true;
            }
        }
        if (!ischange) break;
    }
}