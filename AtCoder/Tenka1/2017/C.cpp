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
    int N;
    cin >> N;

    double w;
    FOR(i, 1, 3501) {
        FOR(j, 1, 3501) {
            if(4 * i * j - N * (i + j)==0) continue;
            w = ((ll) i * j * N) / (4 * i * j - N * (i + j));
//            if (i == 3498 && j == 3498) {
//                cout << 1.0 / i + 1.0 / j + 1.0 / w << endl;
//            }
            if ((double) ((ll) i * j * N) / (4 * i * j - N * (i + j)) - w == 0 && w > 0) {
//                cout << (double) (i * j * N) / (4 * i * j - N * (i + j)) << endl;
//                cout << 1.0 / i + 1.0 / j + 1.0 / w << " " << 4.0 / N << endl;
                printf("%d %d %d\n", i, j, (int)w);
                return 0;
            }
        }
    }

    return 0;
}

