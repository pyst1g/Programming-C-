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


int main() {
    int n = 14;
    vi a(n);
    rep(i, n) {
        cin >> a[i];
    }
    vi temp;
    ll ma = 0;
    rep(i, n) {
        temp = a;
        if (temp[i] == 0) continue;
        int tempi = temp[i];
        temp[i] = 0;
        rep(j, n) temp[j] += tempi / n;
        rep(j, tempi % n) temp[(i + j + 1) % n]++;
        ll score = 0;
        rep(j, n) {
            if (temp[j] % 2 == 0) score += temp[j];
        }
        ma = max(ma, score);
    }

    cout << ma << endl;
    return 0;
}