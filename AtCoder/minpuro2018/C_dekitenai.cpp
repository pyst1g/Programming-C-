// finish date: 2018/02/10

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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

int N;
vi x, c, v;
ll ans = 0;


void dfs_NS(int l, int r, map<int, ll> &mp, ll money, vl we, vl va, ll value = 0, ll weight = 0) {
    if (weight > money) return;
    mp[weight] = max(mp[weight], value);
    if (l >= r) return;
    dfs_NS(l + 1, r, mp, money, we, va, value + va[l], weight + we[l]);
    dfs_NS(l + 1, r, mp, money, we, va, value, weight);

}

ll Knapsack(vl we, vl va, ll money) {
    if (N == 1) {
        if (we[0] <= money) return va[0];
        else return 0;
    }
    map<int, ll> mp1, mp2;
    dfs_NS(0, N / 2, mp1, money,we,va);
    dfs_NS(N / 2, N, mp2, money,we,va);
    ll pre = -1;
    for (auto entry = mp1.begin(); entry != mp1.end();) {
        if (entry->second < pre) {
            int eraser = entry->first;
            entry++;
            mp1.erase(eraser);
        } else {
            pre = entry->second;
            entry++;
        }
    }
    pre = -1;
    for (auto entry = mp2.begin(); entry != mp2.end();) {
        if (entry->second < pre) {
            int eraser = entry->first;
            entry++;
            mp2.erase(eraser);
        } else {
            pre = entry->second;
            entry++;
        }
    }

    vl val1(mp1.size()), val2(mp2.size());
    vl wei1(mp1.size()), wei2(mp2.size());
    int e = 0;
    for (pair<int, ll> entry:mp1) {
        wei1[e] = entry.first;
        val1[e] = entry.second;
        e++;
    }
    e = 0;
    for (pair<int, ll> entry:mp2) {
        wei2[e] = entry.first;
        val2[e] = entry.second;
        e++;
    }

    ll ma = 0;
    int t;
    rep(i, wei1.size()) {
        ll goal = money - wei1[i];
        int l = 0, r = wei2.size() - 1;
        int m;
        while (l <= r) {
            m = (l + r) / 2;
            if (wei2[m] <= goal) {
                t = m;
                l = m + 1;
            } else {
                r = m - 1;
            }
        }
        ma = max(ma, val1[i] + val2[t]);
    }
    return ma;
}


ll buy(ll money, int count) {
    ll ma = LONG_LONG_MAX;

    FOR(i, 1, 1 << N) {
        if (__builtin_popcount(i) == count) {
            vl weight;
            vl value;
            rep(j, N) {
                if (!(i >> j & 1)) {
                    weight.push_back(c[j]);
                    value.push_back(v[j]);
                }
            }
            ma = min(ma, Knapsack(weight, value, money));
        }
    }
    if(ma == LONG_LONG_MAX) return 0;
    return ma;
}

void dfs(ll money = 0, int idx_X = 0) {
    if (idx_X >= N) return;
    ans = max(ans, buy(money, idx_X));
    dfs(money + x[idx_X], idx_X + 1);
}


int main() {

    cin >> N;
    x = vi(N);
    c = vi(N);
    v = vi(N);
    rep(i, N) cin >> x[i];
    rep(i, N) cin >> c[i];
    rep(i, N) cin >> v[i];
    dfs();
    cout << ans << endl;
    return 0;
}


