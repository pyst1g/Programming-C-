// finish date: 2018/01/17
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

string changeBase(int N, int b, int digit = -1) {
    string s = "";
    while (N != 0) {
        s = to_string(N % b) + s;
        N /= b;
    }
    if (digit != -1) {
        while (s.length() < digit) {
            s = "0" + s;
        }
    }
    return s;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N);
    rep(i, N) cin >> a[i];

    int t_score, a_score;
    int sumT, sumA;
    int maxT = -INF;
    rep(i, N) {
        a_score = -INF;
        t_score = -INF;
        rep(j, N) {
            if (i == j) continue;
            sumA = 0;
            sumT = 0;
            FOR(k, min(i, j), max(i, j)+1) {
                if ((k - min(i, j)) % 2 == 0) sumT += a[k];
                else sumA += a[k];
            }
            if (sumA > a_score) {
                a_score = sumA;
                t_score = sumT;
            }
        }
        maxT = max(maxT, t_score);
    }
    cout << maxT << endl;
    return 0;
}
