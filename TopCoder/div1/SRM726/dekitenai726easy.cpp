// finish date: 2018/01/11
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long


class Unpacking {
public:
    bool isExist(char c, string str) {
        rep(i, str.length()) {
            if (c == str[i]) return true;
        }
        return false;
    }

    int fact(int n) {
        int ans = 1;
        FOR(i, 1, n + 1) {
            ans *= i;
        }
        return ans;
    }

    int minDP(vector<int> c, vector<int> cost, int K) {
        int N = c.size();
        int minCost = INT_MAX;
        vector<vector<int>> table(N + 1, vector<int>(K, INT_MAX));
        rep(i, N + 1) table[i][0] = 0;
        rep(i, N) {
            rep(j, K) {
                if (table[i][j] != INT_MAX) {
                    if (j + c[i] < K) {
                        table[i + 1][j + c[i]] = min(table[i + 1][j + c[i]], table[i][j] + cost[i]);
                    } else {
                        minCost = min(minCost, table[i][j] + cost[i]);
                    }
                }
            }
        }
        return minCost;
    }

    int getcost(vector<int> a, vector<int> b, vector<int> cost, int K) {
        int N = a.size();
        vector<int> c(a.size());
        int minCost;

        rep(i, N) c[i] = a[i] - 1;
        minCost = minDP(c, cost, K);

        rep(i, N) c[i] = b[i] - 1;
        minCost = min(minCost, minDP(c, cost, K));

        rep(i, N) c[i] = a[i] + b[i];
        minCost = min(minCost, minDP(c, cost, 2 * K - 1));

        if (minCost == INT_MAX) return -1;
        return minCost;
    }

    int main() {
        return 0;
    }
};