// finish date: 2018/01/16
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
#define bigmod 1000000007
#define INF 500000000
const int limit = 100;

vector<vector<bool>> isPassed(limit, vector<bool>(limit, 0));
int vx[4] = {1, -1, 0, 0};
int vy[4] = {0, 0, -1, 1};
double prob[4];

class CrazyBot {
public:
    double dfs(int n, double p, int x = limit / 2, int y = limit / 2) {
        if (n == 0) return p;
        double sum = 0;
        int nx, ny;
        rep(i, 4) {
            nx = x + vx[i];
            ny = y + vy[i];
            if (isPassed[nx][ny]) continue;
            isPassed[nx][ny] = true;
            sum += dfs(n - 1, p * prob[i], nx, ny);
            isPassed[nx][ny] = false;
        }
        return sum;
    }

    double getProbability(int n, int east, int west, int south, int north) {
        isPassed[limit/2][limit/2] = true;
        prob[0] = (double) east / 100;
        prob[1] = (double) west / 100;
        prob[2] = (double) south / 100;
        prob[3] = (double) north / 100;
        return dfs(n, 1.0);
    }
};

