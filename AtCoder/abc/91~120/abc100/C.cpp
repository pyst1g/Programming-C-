// finish date: 2018/06/16
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>
#include <functional>

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

int cnt_div2(int n) {
    int cnt = 0;
    while (n % 2 == 0) {
        n /= 2;
        cnt++;
    }
    return cnt;
}


int main() {
    int N;
    cin >> N;
    vi a(N);
    int cnt = 0;
    rep(i, N) {
        cin >> a[i];
        cnt += cnt_div2(a[i]);
    }
    cout << cnt << endl;


    return 0;
}




