// finish date: 2018/10/08

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
typedef pair<ll, pair<int, int>> plii;
const int bigmod = 1000000007;
const int INF = 1050000000;
const long long INFll = 100000000000000000;

struct hxy {
    int h, x, y;

    bool operator<(const hxy &another) const {
        //メンバ変数であるnum1で比較した結果を
        //この構造体の比較とする
        return h < another.h;
    }
};

int main() {
    int N;
    cin >> N;
    vector<hxy> p(N);
    rep(i, N) {
        int in1, in2, in3;
        cin >> in1 >> in2 >> in3;
        p[i].h = in3;
        p[i].x = in1;
        p[i].y = in2;
    }
    sort(p.begin(), p.end());
    reverse(p.begin(), p.end());
    rep(x, 101) {
        rep(y, 101) {
            int H = p[0].h + abs(x - p[0].x) + abs(y - p[0].y);
            FOR(i, 1, N) {
                int check = p[i].h + abs(x - p[i].x) + abs(y - p[i].y);
                if (!((p[i].h == 0 && check >= H) || (p[i].h != 0 && check == H))) break;
                if (i == N - 1) {
                    cout << x << " " << y << " " << H << endl;
                    return 0;
                }
            }
        }
    }


    return 0;
}

