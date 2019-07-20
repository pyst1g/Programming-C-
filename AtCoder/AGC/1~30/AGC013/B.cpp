// finish date: 2018/07/12
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


int main() {
    int N, M;
    cin >> N >> M;
    list<int> lst;
    vb used(N, false);
    vvi edge(N);
    rep(i, M) {
        int A, B;
        cin >> A >> B;
        A--;
        B--;
        edge[A].push_back(B);
        edge[B].push_back(A);

        if (i == 0) {
            lst.push_front(A);
            lst.push_back(B);
            used[A] = true;
            used[B] = true;
        }
    }
    bool flg;
    //左端点
    do {
        flg = false;
        for (int to:edge[lst.front()]) {
            if (!used[to]) {
                lst.push_front(to);
                used[to] = true;
                flg = true;
                break;
            }
        }
    } while (flg);
    //右端点
    do {
        flg = false;
        for (int to:edge[lst.back()]) {
            if (!used[to]) {
                lst.push_back(to);
                used[to] = true;
                flg = true;
                break;
            }
        }
    } while (flg);

    cout << lst.size() << endl;
    for (int e:lst) {
        cout << e + 1 << " ";
    }
    cout << endl;

    return 0;
}

