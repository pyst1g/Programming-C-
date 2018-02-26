// finish date: 2018/01/21
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    int A;
    rep(i, N) {
        cin >> A;
        mp[A]++;
    }
    for (auto itr:mp) {
        if (itr.first == 0) {
            if (N % 2 == 1 && itr.second == 1) continue;
            else {
                cout << 0 << endl;
                return 0;
            }
        }
        if (itr.second != 2) {
            cout << 0 << endl;
            return 0;
        }
    }
    int ans = 1;
    rep(i, N / 2) {
        ans = mul(ans, 2);
    }
    cout << ans << endl;

    return 0;
}
