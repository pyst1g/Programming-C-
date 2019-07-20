// finish date: 2018/03/14

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
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>


int main() {
    int N, x;
    cin >> N >> x;
    if (x == 1 || x == 2 * N - 1) {
        cout << "No" << endl;
        return 0;
    }
    if (N == 2) {
        if (x != 2) cout << "No" << endl;
        else {
            cout << "Yes" << endl;
            puts("1");
            puts("2");
            puts("3");
        }
        return 0;
    }
    vi arr(2 * N - 1, 0);
    vb used(2 * N, false);
    used[0] = true;
    if (x < 3) {
        arr[N - 1] = x;
        arr[N - 2] = x - 1;
        arr[N] = x + 1;
        arr[N + 1] = x + 2;
        used[x] = used[x - 1] = used[x + 1] = used[x + 2] = true;
    } else {
        arr[N - 1] = x;
        arr[N - 2] = x + 1;
        arr[N] = x - 1;
        arr[N + 1] = x - 2;
        used[x] = used[x + 1] = used[x - 1] = used[x - 2] = true;
    }
    int idx = 1;
    rep(i, 2 * N - 1) {
        if (arr[i] != 0) continue;
        while (used[idx]) idx++;

        arr[i] = idx;
        idx++;
    }


    cout << "Yes" << endl;
    rep(i, 2 * N - 1) cout << arr[i] << endl;


    return 0;
}