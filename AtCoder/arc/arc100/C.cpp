// finish date: 2018/07/01
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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
typedef vector<bool> vb;
typedef vector<vector<bool>> vvb;
typedef vector<string> vs;
typedef vector<char> vc;
typedef vector<vector<char>> vvc;
typedef pair<int, int> pii;
const int bigmod = 1000000007;
const int INF = 1050000000;


int main() {
    int N;
    cin >> N;
    vi A(N);
    rep(i, N) cin >> A[i];
    rep(i, N) A[i] -= i + 1;
    sort(A.begin(), A.end());
    int b = A[N / 2];
    ll sum = 0;
    rep(i, N) {
        sum += abs(A[i] - b);
    }
    cout<<sum<<endl;

    return 0;

}
