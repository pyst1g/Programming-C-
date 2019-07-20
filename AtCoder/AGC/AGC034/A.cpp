// finish date: 2019/06/03

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
const int bigmod = 998244353;
const int INF = 1050000000;
const long long INFll = 100000000000000000;


int main() {
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    string S;
    cin >> S;
    bool isreachedA = true;
    bool isreachedB = true;
    FOR(i, A, C - 1) if ((S[i] == S[i + 1]) && (S[i + 1] == '#')) isreachedA = false;
    FOR(i, B, D - 1) if ((S[i] == S[i + 1]) && (S[i + 1] == '#')) isreachedB = false;
    bool caseCD = false;
    if (C > D) {
        FOR(i, B - 1, D) {
            if ((S[i - 1] == S[i]) && (S[i] == S[i + 1]) && (S[i + 1] == '.')) caseCD = true;
        }
    } else {
        caseCD = true;
    }
    if (isreachedA && isreachedB && caseCD) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }


    return 0;
}
