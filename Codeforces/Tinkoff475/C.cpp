// finish date: 2018/04/18

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

//足し算
int add(int a, int b) {
    return (a + b) % bigmod;
}

//引き算
int sub(int a, int b) {
    return (a - b + bigmod) % bigmod;
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

//割り算  -  逆元(求めたい数とbigmodを渡す)
int divine(int a, int p = bigmod, int b = -1) {
    if (b < 0) b = p - 2;  //int gyakugen(int a, int p, int b = p - 2とできなかったため。)
    if (b == 0) return 1;
    else if (b % 2 == 0) {
        int d = divine(a, p, b / 2);
        return mul(d, d);
    } else {
        return mul(a, divine(a, p, b - 1));
    }
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
    int n, a, b, k;
    cin >> n >> a >> b >> k;
    n++;
    string s;
    cin >> s;
    if (n <= k) {
        int ans = 0;
        rep(i, n) {
            if (s[i] == '+') ans = add(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
            else ans = sub(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
        }
        cout << ans << endl;
        return 0;
    }
    int ans = 0;
    rep(i, k) {
        if (s[i] == '+') ans = add(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
        else ans = sub(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
    }
    int t = n / k;
    int kouhi = mul(modpow(b, k), divine(modpow(a, k)));
    if (kouhi == 1) ans =mul(ans,t);
    else ans = mul(ans, mul(sub(1, modpow(kouhi, t)), divine(sub(1, kouhi))));
    FOR(i, k * t, n) {
        if (s[i] == '+') ans = add(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
        else ans = sub(ans, mul(modpow(a, n - i - 1), modpow(b, i)));
    }
    cout << ans << endl;


    return 0;
}