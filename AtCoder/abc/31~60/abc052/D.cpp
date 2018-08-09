// finish date: 2018/02/02
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
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000

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


int main() {
    int N, A, B;
    cin >> N >> A >> B;
    ll total = 0;
    vi X(N);
    rep(i, N) cin >> X[i];
    //sort(X.begin(),X.end());
    FOR(i, 1, N) {
        total += min((ll)A * (X[i] - X[i - 1]), (ll)B);
    }
    cout << total << endl;

    return 0;
}

