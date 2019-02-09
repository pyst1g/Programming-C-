// finish date: 2018/09/284

/*
 * 実装したくないです
 */

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

string changeBase(int N, int b, int digit = -1) {
    string s = "";
    while (N != 0) {
        s = to_string(N % b) + s;
        N /= b;
    }
    if (digit != -1) {
        while (s.length() < digit) {
            s = "0" + s;
        }
    }
    return s;
}


int main() {
    int L;
    cin >> L;
    vi o1, o2, o3;
    string S = changeBase(L, 4);
    int dig = S.length();
    int N = 20;
    o1.push_back(0);
    o2.push_back(1);
    o3.push_back(0);
    o1.push_back(0);
    o2.push_back(dig);
    o3.push_back((int) round(pow(4, dig - 1)));
    FOR(i, 1, dig) {
        rep(j, 4) {
            o1.push_back(i);
            o2.push_back((i == dig - 1) ? N - 1 : i + 1);
            o3.push_back((int) round(pow(4, dig - i - 1)) * j);
        }
    }
    rep(i, o1.size()) {
        cout << o1[i] << " " << o2[i] << " " << o3[i] << endl;
    }

    return 0;
}

