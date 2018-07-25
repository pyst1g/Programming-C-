// finish date: 2018/07/25
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
    int A, B, C;
    cin >> A >> B >> C;
    if (A == B && B == C) {
        if (A & 1) cout << 0 << endl;
        else cout << -1 << endl;
        return 0;
    }
    int cnt = 0;
    while (!(A & 1 || B & 1 || C & 1)) {
        cnt++;
        int a = A, b = B, c = C;
        A = (b + c) / 2;
        B = (c + a) / 2;
        C = (a + b) / 2;
    }

    cout << cnt << endl;

    return 0;
}

