// finish date: 2018/08/13
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

string solve(int N) {
    if (N == 0) return "0";
    string s = "";
    int i = 0;
    while (N != 1) {
        if (abs(N) % 2 == 0) {
            s = '0' + s;
            N /= -2;
        } else {
            s = '1' + s;
            N = (N - 1) / -2;
        }
    }
    return '1' + s;
}

int main() {
    int N;
    cin >> N;
    cout << solve(N) << endl;


    return 0;
}


