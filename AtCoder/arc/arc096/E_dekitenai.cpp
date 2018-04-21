// finish date: 2018/04/21

#include <bits/stdc++.h>

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
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>

int N, M;

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % M) * (b % M)) % M);
}

//足し算
int add(int a, int b) {
    return (a + b) % M;
}

//引き算
int sub(int a, int b) {
    return (a - b + M) % M;
}

int modpow(int a, int b) {
    if (b == 0) return 1;
    int temp = modpow(a, b / 2);
    if (b % 2 == 1) return mul(mul(temp, temp), a);
    else {
        return mul(temp, temp);
    }
}

int main() {
    cin >> N >> M;
    vi t(N + 2);
    t[0] = 1;
    FOR(i, 1, t.size()) {
        t[i] = mul(t[i - 1], 2);
    }
    vi two(N + 1);
    rep(i, two.size()) {
        two[i] = modpow(2, t[i + 1] - 1);
    }
//    two[0] = 1;
//    FOR(i, 1, N + 1) {
//        two[i] = mul(two[i - 1], 2);
//    }
//    cout << mul(mul(mul(two[N - 1], 2), two[N - 1]), N) << endl;
    int ans = 0;
    rep(i, N) {
        ans = add(ans, mul(t[N - i - 1], modpow(2, modpow(2, N - i - 1))));
        ans = add(ans, modpow(2, modpow(2, N - i - 1)));
    }
    cout << sub(modpow(2, modpow(2, N)), ans) << endl;

    return 0;
}