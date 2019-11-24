// finish date: 2019/07/20

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
    int N;
    cin >> N;
    vi A(N);
    int ma = 0, ma2 = 0;
    map<int, int> cnt;
    rep(i, N) {
        cin >> A[i];
        if (A[i] > ma) {
            ma2 = ma;
            ma = A[i];
        } else if (A[i] > ma2) {
            ma2 = A[i];
        }
        cnt[A[i]]++;
    }
    rep(i, N) {
        if (A[i] != ma) {
            cout << ma << endl;
        } else {
            if (cnt[A[i]] > 1) cout << A[i] << endl;
            else cout << ma2 << endl;
        }
    }


    return 0;
}
