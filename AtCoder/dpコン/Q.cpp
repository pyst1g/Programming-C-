// finish date: 2019/2/24

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


struct segment_tree_max {
    vector<ll> nodes;
    int sz; //木の一番下のノード数
    int N; //セグメント木の全部のノード数

    //初期化(Aに値を入れると、木をすべて構築してくれる
    segment_tree_max(int n, vector<ll> A = {}) {
        sz = 1 << (int) (ceil(log2(n)));
        N = 1;
        while (N < sz) N *= 2;
        N = N * 2 - 1;
        nodes = vector<ll>(N);
        rep(i, N) nodes[i] = -INFll;
        if (!A.empty()) {
            rep(i, sz) {
                update_tree(A[i], i);
            }
        }
    }

    //木の更新
    void update_tree(ll v, int i) {
        int idx = N / 2 + i;
        while (true) {
            if (v <= nodes[idx]) break;
            nodes[idx] = v;
            if (idx == 0) break;
            idx = (idx - 1) / 2;
        }
    }


    //範囲指定してクエリを処理する
    ll get_query(int a, int b) {
        return get_query(a, b, 0, 0, sz - 1);
    }

private:
    ll get_query(int a, int b, int idx, int l, int r) {
        if (N <= idx) {
            return -INFll;
        }
        if (a <= l && r <= b) {
            return nodes[idx];
        }
        ll valL = -INF;
        ll valR = -INF;
        if ((l + r) / 2 >= a && b >= l) {
            valL = get_query(a, b, idx * 2 + 1, l, (l + r) / 2);
        }
        if (r >= a && b >= (l + r) / 2 + 1) {
            valR = get_query(a, b, idx * 2 + 2, (l + r) / 2 + 1, r);
        }
        return max(valL, valR);
    }
};

int main() {
    int N;
    cin >> N;
    N++;
    vi h(N), a(N);
    h[0] = a[0] = 0;
    FOR(i, 1, N) cin >> h[i];
    FOR(i, 1, N) cin >> a[i];

    segment_tree_max st(N);
    st.update_tree(a[0], h[0]);
    FOR(i, 1, N) {
        st.update_tree(st.get_query(0, h[i] - 1) + a[i], h[i]);
    }
    cout << st.get_query(0, N) << endl;

    return 0;
}