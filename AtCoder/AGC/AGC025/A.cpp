// finish date: 2018/06/06
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
#define pii pair<int,int>
const int bigmod = 1000000007;
#define INF 1050000000


int main() {
    int N;
    cin >> N;
    int ans = INF;
    FOR(i, 1, N / 2 + 1) {
        int A = i;
        int B = N - A;
        int sum = 0;
        while (A != 0) {
            sum += A % 10;
            A /= 10;
        }
        while (B != 0) {
            sum += B % 10;
            B /= 10;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;

    return 0;
}



