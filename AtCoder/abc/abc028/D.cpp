// finish date: 2018/01/27
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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 1050000000


int main() {
    int N, K;
    cin >> N >> K;
    ll count = 0;
    count += (ll)(K - 1) * (N - K) * (3 * 2 * 1);
    count += (ll)(N - 1) * 3;
    count += 1;
    printf("%.9f\n", count / pow(N, 3));

    return 0;
}

