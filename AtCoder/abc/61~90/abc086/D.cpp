// finish date: 2018/01/22
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000

vector<vector<int>> table;
int K;

int calc(int i, int j) {
    int sum = 0;
    if (i + K - 1 >= 2 * K) {
        sum += table[(i + K - 1) % (2 * K)][min(j + K - 1, 2 * K - 1)];
        if (j > 0) sum -= table[(i + K - 1) % (2 * K)][j - 1];
    }
    if (j + K - 1 >= 2 * K) {
        sum += table[min(i + K - 1, 2 * K - 1)][(j + K - 1) % (2 * K)];
        if (i > 0) sum -= table[i - 1][(j + K - 1) % (2 * K)];
    }
    if (j + K - 1 >= 2 * K && i + K - 1 >= 2 * K) {
        sum += table[(i + K - 1) % (2 * K)][(j + K - 1) % (2 * K)];
    }
    sum += table[min(i + K - 1, 2 * K - 1)][min(j + K - 1, 2 * K - 1)];
    if (i > 0) sum -= table[i - 1][min(j + K - 1, 2 * K - 1)];
    if (j > 0) sum -= table[min(i + K - 1, 2 * K - 1)][j - 1];
    if (i > 0 && j > 0) sum += table[i - 1][j - 1];
    return sum;

}


int main() {
    int N;
    cin >> N >> K;
    table = vector<vector<int>>(2 * K, vector<int>(2 * K, 0));
    int x, y;
    char c;
    rep(i, N) {
        cin >> x >> y >> c;
        if (c == 'W') x += K;
        table[x % (K * 2)][y % (K * 2)]++;
    }
    rep(i, 2 * K) {
        rep(j, 2 * K) {
            if (i > 0) table[i][j] += table[i - 1][j];
            if (j > 0) table[i][j] += table[i][j - 1];
            if (i > 0 && j > 0) table[i][j] -= table[i - 1][j - 1];

        }
    }
    int ans = -INF;
    int sum;
    rep(i, 2 * K) {
        rep(j, 2 * K) {
            sum = calc(i, j);
            //sum += calc(i, j);
            int ii = (i + K) % (2 * K);
            int jj = (j + K) % (2 * K);
            sum += calc(ii, jj);

            ans = max(ans, sum);
        }
    }
    cout << ans << endl;

    return 0;
}

