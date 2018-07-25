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
    string S;
    cin >> S;
    map<int, int> trans;
    trans[0] = 0;
    trans[1] = 4;
    trans[2] = 6;
    trans[3] = 8;
    vb use = {false, true, true, true, false, true, false, true, false};
    string akihabara = "AKIHABARA";
    rep(i, 1 << 4) {
        vb nowuse = use;
        rep(j, 4) {
            if (i >> j & 1) {
                nowuse[trans[j]] = true;
            }
        }
        string check = "";
        rep(j, 9) {
            if (nowuse[j]) check += akihabara[j];
        }
        if (check == S) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}

