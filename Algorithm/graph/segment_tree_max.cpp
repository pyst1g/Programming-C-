#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)

struct segment_tree_max {
    vector<int> nodes;
    int sz; //木の一番下のノード数
    int N; //セグメント木の全部のノード数

    //初期化(Aに値を入れると、木をすべて構築してくれる
    segment_tree_max(int n, vector<int> A = {}) {
        sz = 1 << (int) (ceil(log2(n)));
        N = 1;
        while (N < sz) N *= 2;
        N = N * 2 - 1;
        nodes = vector<int>(N);
        rep(i, N) nodes[i] = -INF;
        if (!A.empty()) {
            rep(i, sz) {
                update_tree(A[i], i);
            }
        }
    }

    //木の更新
    void update_tree(int v, int i) {
        int idx = N / 2 + i;
        while (true) {
            if (v <= nodes[idx]) break;
            nodes[idx] = v;
            if (idx == 0) break;
            idx = (idx - 1) / 2;
        }
    }


    //範囲指定してクエリを処理する
    int get_query(int a, int b) {
        return get_query(a, b, 0, 0, sz - 1);
    }

private:
    int get_query(int a, int b, int idx, int l, int r) {
        if (N <= idx) {
            return -INF;
        }
        if (a <= l && r <= b) {
            return nodes[idx];
        }
        int valL = -INF;
        int valR = -INF;
        if ((l + r) / 2 >= a && b >= l) {
            valL = get_query(a, b, idx * 2 + 1, l, (l + r) / 2);
        }
        if (r >= a && b >= (l + r) / 2 + 1) {
            valR = get_query(a, b, idx * 2 + 2, (l + r) / 2 + 1, r);
        }
        return max(valL, valR);
    }
};