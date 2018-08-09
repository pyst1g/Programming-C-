// finish date: 2018/02/03
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

vi memo;
vector<pair<int, int>> boxes;
int N;

int memoization(int t = 0) {
    if (memo[t] != 0) return memo[t];
    rep(i, N) {
        if (boxes[t].first > boxes[i].first && boxes[t].second > boxes[i].second) {
            memo[t] = max(memo[t], memoization(i) + 1);
        }
    }
    if (memo[t] == 0) memo[t] = 1;
    return memo[t];
}


int main() {
    cin >> N;
    memo = vi(N, 0);
    boxes = vector<pair<int, int>>(N);
    int w, h;
    rep(i, N) {
        cin >> w >> h;
        boxes[i] = {w, h};
    }
    sort(boxes.begin(),boxes.end());
    rep(i, N) memoization(i);
    int ma = -INF;
    rep(i, N) ma = max(ma, memo[i]);
    cout << ma << endl;
    return 0;
}

