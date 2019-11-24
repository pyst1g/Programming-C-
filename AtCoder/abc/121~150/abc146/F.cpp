// finish date: 2019/11/24

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
const int INF = 1000000007;
const long long INFll = 100000000000000000;


int main() {
    int N, M;
    cin >> N >> M;
    string S;
    cin >> S;
    reverse(S.begin(), S.end());
    vi deme;
    vi max_progress(N + 1, 0);
    FOR(i, 1, N + 1) {
        if (S[i] == '0'){
            max_progress[i] = i;
        } else{
            max_progress[i] = max_progress[i - 1];
        }
    }
    int pos = 0;
    while (pos != N) {
        int nextpos = min(pos + M, N);
        if (pos == max_progress[nextpos]) {
            cout << -1 << endl;
            return 0;
        }
        deme.push_back(max_progress[nextpos] - pos);
        pos = max_progress[nextpos];
    }

    reverse(deme.begin(), deme.end());
    rep(i, deme.size()) {
        cout << deme[i] << " ";
    }
    cout << endl;

    return 0;
}
