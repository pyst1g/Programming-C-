// finish date: 2018/06/27
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;

struct segment_tree_sum {
    vector<int> nodes;
    int sz; //木の一番下のノード数
    int N; //セグメント木の全部のノード数

    //初期化(Aに値を入れると、木をすべて構築してくれる
    segment_tree_sum(int n, vector<int> A = {}) {
        sz = 1 << (int) (ceil(log2(n)));
        N = 1;
        while (N < sz) N *= 2;
        N = N * 2 - 1;
        nodes = vector<int>(N);
        rep(i, N) nodes[i] = 0;
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
            nodes[idx] += v;
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
            return 0;
        }
        if (a <= l && r <= b) {
            return nodes[idx];
        }
        int valL = 0;
        int valR = 0;
        if ((l + r) / 2 >= a && b >= l) {
            valL = get_query(a, b, idx * 2 + 1, l, (l + r) / 2);
        }
        if (r >= a && b >= (l + r) / 2 + 1) {
            valR = get_query(a, b, idx * 2 + 2, (l + r) / 2 + 1, r);
        }
        return valL + valR;
    }
};

class MajoritySubarray {
public:
    long long getCount(int n, int seed, int m) {
        vl A(n);
        rep(i, n) {
            A[i] = (seed / (1 << 16)) % m;
            seed = (seed * (ll) 1103515245 + 12345) % (1 << 31);
        }
        ll cnt = 0;
        rep(i, m) {
            vi b(n + 1, 0);
            rep(j, n) {
                b[j + 1] = b[j];
                if (A[j] == i) b[j + 1]++;
                else b[j + 1]--;
            }
            segment_tree_sum st(2 * n + 1);
            rep(j, n + 1) {
                st.update_tree(1, b[j] + n);
                if (b[j] + n - 1 >= 0) {
                    cnt += st.get_query(0, b[j] + n - 1);
                }
            }
        }
        return cnt;
    }

};

int main() {
    MajoritySubarray ms;
    cout << ms.getCount(100000, 114, 11) << endl;
}