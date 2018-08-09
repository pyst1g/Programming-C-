// finish date: 2018/08/06
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

int N, M;
int ma = 1000;
vvi state(ma, vi(ma, 0));

int rev(int i) {
    string s = to_string(i);
    reverse(s.begin(), s.end());
    return stoi(s);
}

int solve(int i, int j) {

    if (i == 0 || j == 0) return -1;
    if (state[i][j] == 1 || state[i][j] == -1) return state[i][j];
    else if (state[i][j] == 2) return 1;
    else state[i][j] = 2;

    int x = i;
    int y = j;
    if (i < j) i = rev(i);
    else j = rev(j);

    if (i < j) return state[x][y] = solve(i, j - i);
    else return state[x][y] = solve(i - j, j);


//    if (i > j) {
//        state[i][j] = 2;
//        return state[i][j] = solve(j, i);
//    } else if (i == 0) return state[i][j] = -1;
//    else if (state[i][j] == 2) return state[i][j] = 1;
//    else if (state[i][j] == 0) state[i][j] = 2;
//    else return state[i][j];
//
//    i = rev(i);
//    if (i < j) return state[i][j] = solve(i, j - i);
//    else return state[i][j] = solve(i - j, j);


}

int main() {
    cin >> N >> M;

    rep(i, ma) {
        rep(j, ma) {
            state[i][j] = solve(i, j);
        }
    }
    int cnt = 0;
    rep(i, N + 1) {
        rep(j, M + 1) {
            if (state[i][j] == 1) cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}

