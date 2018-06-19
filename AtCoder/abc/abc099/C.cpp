// finish date: 2018/06/10
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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000

void deriv(int N, vi &ope, int base) {
    int c = base;
    while (c <= N) {
        rep(i, N) {
            if (i + c >= N) break;
            ope[i + c] = min(ope[i + c], ope[i] + 1);
        }
        c *= base;
    }
}

int main() {
    int N;
    cin >> N;
    N++;
    vi ope(N);
    rep(i, N) ope[i] = i;
    deriv(N, ope, 6);
    deriv(N, ope, 9);
    cout << ope[N - 1] << endl;

    return 0;
}




