// finish date: 2018/07/11
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<vector<vector<double>>> vvvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

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


int main() {
    int N, M;
    cin >> N >> M;

    vi a(M), b(M);
    vl c(M);
    rep(i, M) {
        cin >> a[i] >> b[i] >> c[i];
        a[i]--;
        b[i]--;
        c[i] *= -1;
    }
    vl dist;
    vb negative;
    BellmanFord2(0, N, M, a, b, c, dist,negative);
    if(!negative[N-1]){
        cout << -dist[N - 1] << endl;
    } else {
        cout << "inf" << endl;
    }

//    vector<vector<pair<ll, int>>> edge(N);
//    rep(i, M) {
//        int a, b, c;
//        cin >> a >> b >> c;
//        a--;
//        b--;
//        c *= -1;
//        edge[a].push_back(make_pair(c, b));
//    }
//    vl dist;
//    if (BellmanFord(0, N, edge, dist)) {
//        cout << -dist[N - 1] << endl;
//    } else {
//        cout << "inf" << endl;
//    }

    return 0;
}

