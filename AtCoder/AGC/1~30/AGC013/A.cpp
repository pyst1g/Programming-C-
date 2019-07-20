// finish date: 2018/04/16

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
    int N;
    cin >> N;
    vi a(N);
    rep(i, N) cin >> a[i];
    int ans = 0;
    int i = 0;
    while (i < N) {
        ans++;
        while (i + 1 < N && a[i] == a[i + 1]) i++;
        if (i == N - 1) break;
        if (a[i] < a[i + 1]) {
            while (i + 1 < N && a[i] <= a[i + 1]) i++;
        } else {
            while (i + 1 < N && a[i] >= a[i + 1]) i++;
        }
        i++;
    }
    cout << ans << endl;

    return 0;
}