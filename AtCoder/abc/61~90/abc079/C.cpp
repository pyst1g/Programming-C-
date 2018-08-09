// finish date: 2018/01/24
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
#define bigmod 1000000007
#define INF 500000000

string S;
string ans = "";

void dfs(string op = "") {
    if (ans != "") return;
    if (op.size() == 3) {
        int sum = S[0] - '0';
        rep(i, 3) {
            if (op[i] == '+') sum += S[i + 1] - '0';
            else sum -= S[i + 1] - '0';
        }
        if (sum == 7) {
            ans += S[0];
            rep(i, 3) {
                ans += op[i];
                ans += S[i + 1];
            }
            ans += "=7";
        }
        return;
    }

    dfs(op + "+");
    dfs(op + "-");

}

int main() {
    cin >> S;
    dfs();
    cout << ans << endl;

    return 0;
}

