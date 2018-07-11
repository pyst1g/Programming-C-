// finish date: 2018/07/07
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>>
        vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>>
        vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int,int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;

vi order;

vl dijkstra(int s, int V, vector<vector<pli>> edge) {
    vl dist(V, LONG_LONG_MAX / 4); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<plii, vector<plii>, greater<plii>> pq;
    pq.push(plii(0, pii(s,0)));
    while (!pq.empty()) {
        ll d;
        pii p;
        int t;
        int od;
        tie(d, p) = pq.top();
        tie(t,od) = p;
        pq.pop();
        order[t] = od;
        if (used[t]) continue;
        used[t] = true;
        dist[t] = d;
        for (pii e:edge[t]) {
            //if (dist[e.second] < d + e.first) continue;
            pq.push(plii(e.first - d, pii(e.second,od+1)));
        }
    }
    return dist;
}

bool dijkstra2(int s, int V, vector<vector<pli>> edge) {
    vl dist(V, LONG_LONG_MAX / 4); //INFの値がこれでいいか確認するべき
    vb used(V, false);
    priority_queue<pli, vector<pli>, greater<pli>> pq;
    pq.push(pli(0, s));
    while (!pq.empty()) {
        ll d;
        int t;
        tie(d, t) = pq.top();
        pq.pop();
        if (used[t]) continue;
        used[t] = true;
        if (!(dist[t] == 0 || dist[t] != d)) return false;
        dist[t] = d;
        for (pli e:edge[t]) {
            //if (dist[e.second] < d + e.first) continue;
            pq.push(pli(e.first - d, e.second));
        }
    }
    return true;
}


struct Union_Find {
    vector<int> parent;
    vector<int> sizes;
    int setnum = 0;

    Union_Find(int n) : parent(n), sizes(n, 1) {
        rep(i, n) parent[i] = i;
        setnum = n;
    }

    int find(int x) {
        if (x == parent[x]) return x;
        return parent[x] = find(parent[x]);
    }

    void unite(int x, int y) {
        x = find(x);
        y = find(y);

        if (x == y) return;

        if (sizes[x] < sizes[y]) swap(x, y);

        parent[y] = x;
        sizes[x] += sizes[y];
        setnum--;
    }

    bool isSame(int x, int y) {
        return find(x) == find(y);
    }

    int size(int x) {
        return sizes[find(x)];
    }

};


int main() {
    int n, m;
    cin >> n >> m;
    order = vi(n,0);
    vi u(m);
    vi v(m);
    vi s(m);
    vb ent(m, false);
    vector<vector<pli>> edge(n);
    rep(i, m) {
        cin >> u[i] >> v[i] >> s[i];
        u[i]--;
        v[i]--;
        ent[v[i]] = true;
        edge[u[i]].emplace_back(make_pair(s[i], v[i]));
    }
//    vl cst(n, 0);
//    rep(i, n) {
//        for (auto e:edge[i]) {
//            if (cst[e.second] == 0 || cst[e.second] == cst[i] + e.first) {
//                cst[e.second] = cst[i] + e.first;
//            } else {
//                cout << 0 << endl;
//                return 0;
//            }
//        }
//    }


    int st = 0;
    rep(i, m) {
        if (!ent[v[i]]) {
            st = i;
            break;
        }
    }

//    vl cost(n,0);
//    vb used(n,false);
//    queue<pli> queue1;
//    used[st] = true;
//    for(pli e: edge[st]){
//        queue1.push(e);
//    }
//    while (!queue1.empty()) {
//        ll d;
//        int t;
//        tie(d, t) = queue1.top();
//        queue1.pop();
//        if (used[t]) continue;
//        used[t] = true;
//        if (!(cost[t] == 0 || dist[t] != d)) return false;
//        dist[t] = d;
//        for (pli e:edge[t]) {
//            //if (dist[e.second] < d + e.first) continue;
//            pq.push(pii(d + e.first, e.second));
//        }
//    }

    vl cst = dijkstra(st, n, edge);
    if (!dijkstra2(st, n, edge)) {
        cout << 0 << endl;
        return 0;
    }
//    rep(i, m) {
//        if (cst[v[i]] + cst[u[i]] != s[i]) {
//            cout << 0 << endl;
//            return 0;
//        }
//    }

    map<int, int> focus;
    Union_Find uf(n);
    rep(i, m) {
        if (u[i] == st || v[i] == st) continue;
        uf.unite(u[i], v[i]);
    }


    for (auto e:edge[st]) {
        focus[uf.parent[e.second]]++;
    }

    for (auto e:focus) {
        if (e.second > 1) {
            cout << 1 << endl;
            return 0;
        }
    }

    ll mi = INF;
    for (auto e:edge[st]) {
        mi = min(mi, e.first);
    }

    ll mi2 = INF;
    FOR(i, 1, n) {
        if(order[i]%2){
            mi2 = min(mi2,cst[i]);
        }
    }

    ll mi3 = INF;
    FOR(i, 1, n) {
        if(order[i]%2==0){
            mi3 = min(mi3,cst[i]);
        }
    }
    ll sl = max(1LL,-mi3+1);
    ll sr = mi2-1;
    cout<<max(0LL,sr-sl+1)<<endl;
//    if (mi2 > 0) {
//        cout << mi << endl;
//    } else {
//        cout << max((ll) 0, mi + mi2 - 1) << endl;
//    }
    return 0;
}


