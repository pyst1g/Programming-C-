// finish date: 2018/01/15
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

ll combination(int n, int k) {
    if(k==0) return 1;
    ll ans = 1;
    FOR(i,1, k+1) {
        ans *= n;
        n--;
        ans /= i;
    }
    return ans;
}


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    vector<ll> v(N, 0);
    rep(i, N) cin >> v[i];
    sort(v.begin(), v.end(), greater<ll>());
    double ma = 0;
    rep(i, A) {
        ma += v[i];
    }
    ma /= A;

    ll mi = v[A - 1];
    int mi_nanko = 0; //この値は適当
    int mi_left = 0;
    rep(i, N) {
        if (v[i] == mi) {
            if (mi_nanko == 0) mi_left = i;
            mi_nanko++;
        } else {
            if (mi_nanko != 0) break;
        }
    }

    ll count = 0;
    FOR(i, A - 1, B) {
        if (i == A - 1 || v[0] == v[i]) count += combination(mi_nanko, i - mi_left + 1);
        else break;
    }

    printf("%.6f\n%lld\n", ma, count);
    return 0;
}
