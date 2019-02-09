// finish date: 2018/09/30

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


int main() {
    string s;
    cin >> s;
    int n = s.length();
    if (s[0] == '0' || s[n - 1] == '1') {
        cout << -1 << endl;
        return 0;
    }
    rep(i, n - 1) {
        if (s[max(i, n - i - 2)] != s[min(i, n - i - 2)]) {
            cout << -1 << endl;
            return 0;
        }
    }
    int tmp = 0;
    vi o1, o2;
    FOR(i, 1, n) {
        if (s[i] == '1') {
            while (tmp != i) {
                o1.push_back(i);
                o2.push_back(tmp);
                tmp++;
            }
        }
    }
    o1.push_back(n - 1);
    o2.push_back(n - 2);
    rep(i, o1.size()) {
        cout << o1[i] + 1 << " " << o2[i] + 1 << endl;
    }


    return 0;
}

