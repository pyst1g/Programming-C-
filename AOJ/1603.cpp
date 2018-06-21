// finish date: 2018/06/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    while (true) {
        int n;
        cin >> n;
        if (n == 0) break;
        vi p(n);
        rep(i, n) {
            cin >> p[i];
        }
        int maxDP = n * 1000;
        vector<pii > DP(maxDP, pii(-1, -1));
        DP[0] = pii(0, 0);
        vector<pii > newDP;
        rep(i, n) {
            newDP = vector<pii >(maxDP, pii(-1, -1));
            int otsuri = 1000 - p[i] % 1000;
            if (otsuri == 1000) otsuri = 0;
            for (int j = maxDP - 1; j >= 0; j--) {
                if (DP[j] == pii(-1, -1)) continue;
                bool con1 = newDP[j + otsuri].first < DP[j].first;
                bool con2 = newDP[j + otsuri].first == DP[j].first;
                bool con3 = newDP[j + otsuri].second > DP[j].second + p[i];
                if (con1 || (con2 && con3)) {
                    newDP[j + otsuri] = DP[j];
                    newDP[j + otsuri].second += p[i];
                }
            }
            rep(j, maxDP) {
                if (newDP[j] == pii(-1, -1)) continue;
                if (j >= 500) {
                    bool con1 = newDP[j - 500].first < newDP[j].first + 1;
                    bool con2 = newDP[j - 500].first == newDP[j].first + 1;
                    bool con3 = newDP[j - 500].second > newDP[j].second;
                    if (con1 || (con2 && con3)) {
                        newDP[j - 500] = newDP[j];
                        newDP[j - 500].first++;
                    }
                }
            }
            rep(j, maxDP) {
                if (DP[j].first > newDP[j].first || (DP[j].first == newDP[j].first && DP[j].second < newDP[j].second)) {
                    newDP[j] = DP[j];
                }
            }
            DP = newDP;
        }



        int ma = -1;
        int ansMoney = 0;
        rep(i, maxDP) {
            if (DP[i].first > ma || (DP[i].first == ma && DP[i].second < ansMoney)) {
                ma = DP[i].first;
                ansMoney = DP[i].second;
            }
        }
        cout << ma << " " << ansMoney << endl;

    }


    return 0;
}




