// finish date: 2018/01/14
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

#define bigmod 1000000007
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}


int main() {
    int N, D, K;
    cin >> N >> D >> K;
    vector<int> L(D, 0), R(D, 0);
    rep(i, D) cin >> L[i] >> R[i];
    int S, T;
    bool direction_isRight;
    rep(i, K) {
        cin >> S >> T;
        //direction_isRight = (T - S >= 0);
        rep(j, D) {
            if (T - S >= 0) {
                if (L[j] <= S && S <= R[j]) {
                    S = R[j];
                    if (S >= T) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            } else {
                if (L[j] <= S && S <= R[j]) {
                    S = L[j];
                    if (S <= T) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }

    }

    return 0;
}
