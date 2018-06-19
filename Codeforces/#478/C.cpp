// finish date: 2018/04/30

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

int binary_search(vl HP, ll damage) {
    int n = HP.size();
    if (HP[0] > damage) return -1;
//    if (HP[n - 1] < damage) return n;
    int l = 0;
    int r = n - 1;
    int m = (l + r) / 2;
    while (l <= r) {
        m = (l + r) / 2;
        if (HP[m] <= damage) {
            l = m + 1;
        } else {
            r = m - 1;
        }
    }
    return m;
}


int main() {
    int n, q;
    cin >> n >> q;
    vi a(n);
    vl k(q);
    rep(i, n) {
        cin >> a[i];
    }
    rep(i, q) {
        cin >> k[i];
    }
    vl HP(n);
    rep(i, n) {
        HP[i] = a[i];
        if (i > 0) HP[i] += HP[i - 1];
    }
    ll damage = 0;
    rep(i, q) {
        damage += k[i];
        int death_counter = distance(HP.begin(), upper_bound(HP.begin(), HP.end(), damage));
        if (death_counter == n) cout << n << endl;
        else {
            cout << n - death_counter<< endl;
        }
        if (death_counter == n) damage = 0;
    }


    return 0;
}