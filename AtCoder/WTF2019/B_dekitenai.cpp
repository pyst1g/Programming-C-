// finish date: 2019/2/23

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
    int N, Q;
    cin >> N >> Q;
    vvi lr(Q, vi(2));
    rep(i, Q) cin >> lr[i][0] >> lr[i][1];
    sort(lr.begin(), lr.end());

    set<pii> section;
    section.insert(pii(1, N));
//    bool flag = false;
    rep(i, Q) {
        for (pii e:section) {
            if (e.first < lr[i][0] && lr[i][0] <= e.second) {
                section.insert(pii(e.first, lr[i][0] - 1));
                section.insert(pii(lr[i][0], e.second));
                section.erase(e);
                break;
            }
        }
        for (pii e:section) {
            if (e.first <= lr[i][1] && lr[i][1] < e.second) {
                section.insert(pii(e.first, lr[i][1]));
                section.insert(pii(lr[i][1] + 1, e.second));
                section.erase(e);
                break;
            }
        }
//        if(flag) break;
    }
    vector<pii> sec(section.size());
    int ii = 0;
    for (pii e:section) {
        sec[ii] = pii(e.first, e.second);
        ii++;
    }
//    delete (section);
    int S = sec.size();
    vb check(S, false);
    rep(i, N) {
        rep(j, S) {
            if (lr[i][0] == sec[j].first && lr[i][1] == sec[j].second) {
                check[j] = true;
            }
        }
    }
//    rep(k, 1 << S) {
//        rep(i, S) if (!(k & (1 << i)) && check[i]) goto nex;
//        rep(i, Q) {
//            rep(j,S){
//                if()
//            }
//        }
//
//        nex:;
//    }


    return 0;
}