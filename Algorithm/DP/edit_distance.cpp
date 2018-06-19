int edit_distance(string S, string T) {
    int H = S.length() + 1;
    int W = T.length() + 1;
    vvi dist(H, vi(W, 0));
    rep(i, H) dist[i][0] = i;
    rep(i, W) dist[0][i] = i;

    FOR(i, 1, H) {
        FOR(j, 1, W) {
            dist[i][j] = min(dist[i - 1][j - 1] + ((S[i - 1] == T[j - 1]) ? 0 : 1),
                             min(dist[i - 1][j] + 1, dist[i][j - 1] + 1));
        }
    }

    return dist[H - 1][W - 1];
}