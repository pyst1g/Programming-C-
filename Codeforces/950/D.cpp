// finish date: 2018/03/09

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
    ll n;
    int q;
    cin >> n >> q;

    rep(i, q) {
        ll query;
        cin >> query;
        ll temp = 0;
        while (true) {
            if ((temp % 2 == 0 && query % 2 == 1) || (temp % 2 == 1 && query % 2 == 0)) {
                cout << (query + temp + 1) / 2 << endl;
                break;
            } else {
                query = (query + 1) / 2;
                temp = ((n * 2 - 1) + temp + 1) / 2;
            }
        }
    }

    return 0;
}