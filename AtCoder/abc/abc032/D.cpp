// finish date: 2018/02/09

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

int N, W;
vi v, w;


void dfs(int l, int r, map<int, ll> &mp, ll value = 0, ll weight = 0) {
    if (weight > W) return;
    mp[weight] = max(mp[weight], value);
    if (l >= r) return;
    dfs(l + 1, r, mp, value + v[l], weight + w[l]);
    dfs(l + 1, r, mp, value, weight);

}

void Knapsack1() {
    if (N == 1) {
        if (w[0] <= W) cout << v[0] << endl;
        else cout << 0 << endl;
        return;
    }
    map<int, ll> mp1, mp2;
    dfs(0, N / 2, mp1);
    dfs(N / 2, N, mp2);
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
    vi wei1(mp1.size()), wei2(mp2.size());
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
        int goal = W - wei1[i];
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
    cout << ma << endl;
}


bool Knapsack2() {
    vl DP(N * 1000 + 1, 0);
    rep(i, N) {
        for (int j = 1000 * i; j >= 0; j--) {
            if (j == 0 || DP[j] != 0) {
                DP[j + w[i]] = max(DP[j + w[i]], DP[j] + v[i]);
            }
        }
    }
    ll ma = 0;
    rep(i, W + 1) {
        ma = max(ma, DP[i]);
    }
    cout << ma << endl;
}


void Knapsack3() {
    vl DP(N * 1000 + 1, LONG_LONG_MAX);
    DP[0] = 0;
    rep(i, N) {
        for (int j = 1000 * i; j >= 0; j--) {
            if (DP[j] != LONG_LONG_MAX) {
                DP[j + v[i]] = min(DP[j + v[i]], DP[j] + w[i]);
            }
        }
    }

    for (int i = DP.size() - 1; i >= 0; i--) {
        if (DP[i] <= W) {
            cout << i << endl;
            return;
        }
    }
}


int main() {
    cin >> N >> W;
    v = vi(N);
    w = vi(N);
    rep(i, N) cin >> v[i] >> w[i];

    //1<=wi<=1000かどうかを調べる変数
    bool con = true;
    rep(i, N) {
        if (w[i] > 1000) {
            con = false;
            break;
        }
    }
    if (N <= 30) {
        Knapsack1();
    }else if (con) {
        Knapsack2();
    } else {
        Knapsack3();
    }

    return 0;
}


