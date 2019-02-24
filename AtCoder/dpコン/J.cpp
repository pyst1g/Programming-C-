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

vvvd memo;
int N;

double dfs(int x, int y, int z) {
    if (x < 0 || y < 0 || z < 0) return 0;
    if (memo[x][y][z] != -1) return memo[x][y][z];
    return memo[x][y][z] = (dfs(x - 1, y, z) * x +
                            dfs(x + 1, y - 1, z) * y +
                            dfs(x, y + 1, z - 1) * z) /
                           (x + y + z) +
                           (double) N / (x + y + z);
}

int main() {
    cin >> N;
    vi cnt(3, 0);
    rep(i, N) {
        int a;
        cin >> a;
        cnt[a - 1]++;
    }
    memo = vvvd(N + 1, vvd(N + 1, vd(N + 1, -1)));
    memo[0][0][0] = 0;
    printf("%.10lf\n", dfs(cnt[0], cnt[1], cnt[2]));

    return 0;
}