// finish date: 2018/07/17

//自分で考えて書いたコード
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
//    vi eee(87260);
//    eee[0] = 3797326;
//    eee[1] = eee[0]+98569467;
//    eee[2] = eee[1]+98569467;
//    FOR(i,3,eee.size()){
//        eee[i] = eee[i-1] + 98570272- 98569467;
//    }
//    cout<<eee[eee.size()-1]<<endl;


    ll N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;

    ll diff = abs(A - B);
    N--;
    if ((ll) N * D < diff) {
        cout << "NO" << endl;
        return 0;
    } else if ((ll) N * C <= diff) {
        cout << "YES" << endl;
        return 0;
    } else if (N % 2 == 1 && C <= diff && diff <= D) {
        cout << "YES" << endl;
        return 0;
    } else {
        ll diff2 = abs(A - B);
        if (N % 2 == 1) {
            diff = abs(diff - D);
            diff2 = abs(diff2 - C);
            N--;
        }
        rep(i, N / 2 + 1) {
            ll n = N - 2 * i;
            if (n == 2) {
                int a = 1;
            }
            if ((n * C <= diff && diff <= n * D)
                || (n * C <= diff2 && diff2 <= n * D)) {
                cout << "YES" << endl;
                return 0;
            }
            if ((min(abs(diff - n * C), abs(diff - n * D)) <= i * (D - C)) ||
                (min(abs(diff2 - n * C), abs(diff2 - n * D)) <= i * (D - C))) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }

    cout << "NO" << endl;

    return 0;
}

