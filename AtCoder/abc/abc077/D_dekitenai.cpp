// finish date: 2018/02/16

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
    int K;
    cin >> K;
    ll temp = 0;
    int digitsum;
    int ans = INF;
    FOR(i, 1, 1000000) {
        digitsum = 0;
        temp = (ll) i * K;
        while (temp != 0) {
            digitsum += temp % 10;
            temp /= 10;
        }
        ans = min(ans,digitsum);
    }
    cout<<ans<<endl;
    return 0;
}


