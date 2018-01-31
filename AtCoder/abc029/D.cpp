// finish date: 2018/01/27
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
#define vi vector<int>
#define vvi vector<vector<int>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>5
#define vvb vector<vector<bool>>
#define bigmod 1000000007
#define INF 500000000

int main() {
    string N;
    cin >> N;
    N = "0" + N;
    int ans = 0;
    FOR(i, 1, N.length()) {
        int bi = (N[i] > '1') ? 1 : 0;
        //if (N[i] >= '1') {
        ans += (stoi(N.substr(0, i)) + bi) * (int) (0.5 + pow(10, N.length() - i - 1));
        //}
        if (N[i] == '1') {
            ans++;
            if (i != N.length() - 1) ans += stoi(N.substr(i + 1));
        }
    }

    cout << ans << endl;

    return 0;
}

