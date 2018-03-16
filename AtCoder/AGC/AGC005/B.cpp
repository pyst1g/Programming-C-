// finish date: 2018/03/10

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
    int N;
    cin >> N;
    vi a(N);
    ll ans = 0;
    map<int, int> indice, use;
    rep(i, N) {
        cin >> a[i];
        indice[a[i]] = i + 1;
    }
    use[0] = 0;
    use[N + 1] = 0;

    FOR(i, 1, N + 1) {
        auto itr = use.upper_bound(indice[i]);
        int right = itr->first;
        itr--;
        int left = itr->first;
        ans += (ll) i * (ll) (indice[i] - left) * (right - indice[i]);
        use[indice[i]] = 0;
    }
    cout << ans << endl;


    return 0;
}