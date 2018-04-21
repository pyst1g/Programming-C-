// finish date: 2018/03/23

#include <bits/stdc++.h>

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
    int N;
    cin >> N;
    string S;
    cin >> S;
    if (N == 1) {
        cout << 1 << endl;
        return 0;
    }
    int ma = 1;
    rep(i, N / 2) {
        if (S.substr(0, i + 1) == S.substr(i + 1, i + 1)) ma = i + 1;
    }
    cout << N - ma + 1 << endl;

    return 0;
}