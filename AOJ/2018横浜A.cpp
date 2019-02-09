// finish date: 2018/2/05

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
    int n;
    cin >> n;
    string s0;
    cin >> s0;

    int tempVal = 0;
    bool exVal = false;
    vi val_s0;
    rep(i, s0.length()) {
        if (s0[i] < 'A') {
            tempVal *= 10;
            tempVal += s0[i] - '0';
            exVal = true;
        }
        if (exVal && (s0[i] >= 'A' || i == s0.length() - 1)) {
            val_s0.push_back(-1000000000 + tempVal);
            tempVal = 0;
            exVal = false;
        }
        if (s0[i] >= 'A') {
            val_s0.push_back(s0[i]);
        }
    }


    rep(k, n) {
        string s;
        cin >> s;
        vi val_s;
        rep(i, s.length()) {
            if (s[i] < 'A') {
                tempVal *= 10;
                tempVal += s[i] - '0';
                exVal = true;
            }
            if (exVal && (s[i] >= 'A' || i == s.length() - 1)) {
                val_s.push_back(-1000000000 + tempVal);
                tempVal = 0;
                exVal = false;
            }
            if (s[i] >= 'A') {
                val_s.push_back(s[i]);
            }
        }
        rep(i, min(val_s0.size(), val_s.size())) {
            if (val_s0[i] > val_s[i]) {
                cout << "-" << endl;
                break;
            } else if (val_s0[i] < val_s[i]) {
                cout << "+" << endl;
                break;
            }
            if (i == min(val_s0.size(), val_s.size())-1) {
                if (val_s0.size() <= val_s.size()) {
                    cout << "+" << endl;
                } else {
                    cout << "-" << endl;
                }
            }
        }
    }


    return 0;
}

