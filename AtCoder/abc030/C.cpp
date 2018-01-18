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
    int N, M;
    int X, Y;
    cin >> N >> M >> X >> Y;
    vector<int> a(N), b(M);
    rep(i, N) cin >> a[i];
    rep(i, M) cin >> b[i];
    ll time = 0;
    int ai = 0, bi = 0;
    int count = 0;
    string place = "A";
    while ((place=="A"&&ai < N) || (place =="B"&&bi < M)) {
        if (place == "A") {
            if (a[ai] < time) {
                ai++;
                continue;
            } else {
                time = a[ai]+X;
                ai++;
                place = "B";
            }
        }
        else if (place == "B") {
            if (b[bi] < time) {
                bi++;
                continue;
            } else {
                time = b[bi]+Y;
                bi++;
                place = "A";
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}
