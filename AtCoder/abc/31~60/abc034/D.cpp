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


int main() {
    int N, K;
    cin >> N >> K;
    vi w(N), p(N);
    rep(i, N) cin >> w[i] >> p[i];
    double l = 0, r = 100;
    double m;
    int c = 0;
    while (c <= 100) {
        m = (l + r) / 2;
        map<double, int> mp;
        rep(i, N) {
            mp[(double) w[i] * (p[i] - m) / 100.0]++;
        }
        double dif = 0;
        int count = 0;
        for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
            if (count >= K) break;

            if (count + itr->second <= K) dif += itr->first * itr->second;
            else dif += itr->first * min(0, K - itr->second);
            count += itr->second;
        }
        if (dif < 0) r = m;
        else l = m;
        c++;
    }
    printf("%.9f\n",m);

    return 0;
}


