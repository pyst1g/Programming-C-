// finish date: 2018/07/22
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
    ll sum = 0;
    rep(i, N) {
        cin >> A[i];
        sum += A[i];
    }
    if (sum % ((ll) N * (1 + N) / 2) != 0) {
        cout << "NO" << endl;
        return 0;
    }
    int K = (int) (sum / ((ll) N * (1 + N) / 2));

    vi d(N);
    rep(i, N) {
        d[i] = A[(i + 1) % N] - A[i] - K;
        if (d[i] > 0 || d[i] % N != 0) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout<<"YES"<<endl;

    return 0;
}

