// finish date: 2018/07/07
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
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    int n, m, d;
    cin >> n >> m >> d;

    //2個あるやつ
    int com = max(0, n - d * 2);

    //１こあるやつ
    int semi = d * 2;
    double ans = (double) (m - 1) * (2 * com + semi) / pow(n, 2);
    if (d == 0) ans /= 2;
    printf("%.7f\n", ans);


    return 0;
}

