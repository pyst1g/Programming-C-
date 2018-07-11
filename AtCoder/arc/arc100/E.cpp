// finish date: 2018/07/07
#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
typedef long long ll;
typedef vector<int> vi;
typedef vector <vector<int>> vvi;
typedef vector <vector<vector < int>>>
        vvvi;
typedef vector <ll> vl;
typedef vector <vector<ll>> vvl;
typedef vector<double> vd;
typedef vector <vector<double>> vvd;
typedef vector <vector<vector < double>>>
        vvvd;
typedef vector<bool> vb;
typedef vector <vector<bool>> vvb;
typedef vector <string> vs;
typedef vector<char> vc;
typedef vector <vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    int N;
    cin >> N;
    int num = 1 << N;
    vi A(num);
    rep(i, num) cin >> A[i];
    vector <pii> max1(num), max2(num);
    max1[0] = pii(A[0], 0);
    max2[0] = pii(0, -1);
    FOR(i, 1, num) {
        max1[i] = pii(A[i], i);
        max2[i] = pii(0, -1);
        rep(j, N) {
            if (i & (1 << j)) {
                int idx = i - (1 << j);
                if (max1[i] <= max1[idx]) {
                    if (max1[i] != max1[idx]) {
                        swap(max1[i], max2[i]);
                        max1[i] = max1[idx];
                    }
                    if (max2[i] < max2[idx]) {
                        max2[i] = max2[idx];
                    }
                } else if (max2[i] < max1[idx]) {
                    max2[i] = max1[idx];
                }
            }
        }
//        if (A[i] > max2[i]) {
//            max2[i] = A[i];
//            if (max2[i] > max1[i]) swap(max2[i], max1[i]);
//        }
//        cout << max1[i] + max2[i] << endl;
    }
    int ma = -1;
    FOR(i, 1, num) {
        ma = max(ma, max1[i].first + max2[i].first);
        cout << ma << endl;
    }


    return 0;
}

