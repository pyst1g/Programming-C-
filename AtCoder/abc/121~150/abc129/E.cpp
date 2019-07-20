// finish date: 2019/06/09

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


//足し算
int add(int a, int b) {
    return (int) (((ll) a + b + bigmod) % bigmod);
}

//掛け算
int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int modpow(int a, int b) {
    if (b == 0) return 1;
    int temp = modpow(a, b / 2);
    if (b % 2 == 1) return mul(mul(temp, temp), a);
    else {
        return mul(temp, temp);
    }
}


string L;
int ans;


int dfs(int pos) {
    int tmp = 0;
    if (pos == L.length()) return 1;
    if (L[pos] == '1') {
        tmp = add(tmp, modpow(3, L.length() - pos - 1));
        tmp = add(tmp, mul(2,dfs(pos + 1)));
    } else {
        tmp = add(tmp, dfs(pos + 1));
    }
    return tmp;

}

int main() {
    cin >> L;
    ans = 0;
    ans = dfs(0);
    cout << ans << endl;
    return 0;
}
