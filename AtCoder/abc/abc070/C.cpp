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

ll nCk(int n, int k) {
    if (k == 0) return 1;
    ll ans = 1;
    FOR(i, 1, k + 1) {
        ans *= n;
        n--;
        ans /= i;
    }
    return ans;
}


ll gcd(ll a, ll b){
    if(a< 0) a = -a;
    if(b < 0) b = -b;
    if(a < b){
        swap(a,b);
    }
    ll r = 1; //0以外であれば何でも
    while(r != 0){
        r = a%b;
        a = b;
        b = r;
    }
    return a;
}

int main() {
    int N;
    ll T, ans;
    cin >> N;
    cin >> ans;

    rep(i, N - 1) {
        cin >> T;
        ans *= (T / gcd(T, ans));
    }

    cout << ans << endl;

    return 0;
}
