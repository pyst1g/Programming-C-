// finish date: 2018/05/26

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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    vi count_W(N, 0);
    vi count_E(N, 0);
    rep(i, N) {
        if (i != 0) {
            count_W[i] += count_W[i - 1];
            count_E[i] += count_E[i - 1];
        }
        if (S[i] == 'W') count_W[i]++;
        else count_E[i]++;
    }
    int mi = INF;
    rep(i, N) {
        if (S[i] == 'W') {
            mi = min(mi, count_W[i] - 1 + count_E[N - 1] - count_E[i]);
        } else {
            mi = min(mi, count_W[i] + count_E[N - 1] - count_E[i]);
        }
    }
    cout << mi << endl;

    return 0;
}


