// finish date: 2018/07/02
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
typedef long long ll;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<vector<int>>> vvvi;
typedef vector<ll> vl;
typedef vector<vector<ll>> vvl;
typedef vector<double> vd;
typedef vector<vector<double>> vvd;
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    vector<ll> S(64);
    S[0] = 0;
    FOR(i, 1, 64) {
        S[i] = 9 * ((1LL << i) - 1);
    }
    while (true) {
        ll N;
        cin >> N;
        if (N == 0) break;
        ll cnt = 0;
        int dig = 0;
        while (true) {
            if (cnt + S[dig] * 9 >= N) break;
            cnt += S[dig] * 9;
            dig++;
        }
        int sameNum = (int) ((N - cnt + S[dig] - 1) / S[dig]);
        cnt += (sameNum - 1) * S[dig];
        int num2 = -1;
        string ans = to_string(sameNum);
        bool flg = true;
        while (dig > 1) {
            rep(i, 10) {
                if (!(i == sameNum || num2 == -1 || num2 == i)) continue;
                if (num2 == -1 && i == sameNum) {
                    if (cnt + ((1LL << (dig - 1)) - 1) * 9 >= N) {
                        ans += to_string(i);
                        dig--;
                        break;
                    } else {
                        cnt += ((1LL << (dig - 1)) - 1) * 9;
                    }
                } else {
                    if (cnt + (1LL << (dig - 1)) >= N) {
                        ans += to_string(i);
                        dig--;
                        if (num2 == -1) num2 = i;
                        break;
                    } else {
                        cnt += (1LL << (dig - 1));
                    }
                }
            }
        }
        rep(i, 10) {
            if (num2 == -1) {
                if (i != sameNum) cnt++;
            } else {
                if (i == sameNum || i == num2) cnt++;
            }
            if (cnt == N) {
                ans += to_string(i);
                break;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
