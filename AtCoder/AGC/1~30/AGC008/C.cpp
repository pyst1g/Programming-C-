// finish date: 2018/03/16

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
    int I, O, T, J, L, S, Z;
    cin >> I >> O >> T >> J >> L >> S >> Z;
    ll K = 0;
    K += O * 2;
    K += (I / 2) * 4;
    K += (J / 2) * 4;
    K += (L / 2) * 4;

    if ((I&&J&&L)&&((I % 2 == 1 && J % 2 == 1) || (J % 2 == 1 && L % 2 == 1) || (L % 2 == 1 && I % 2 == 1))) {
        K += 6;
        if ((I != 0 && I % 2 == 0) || (J != 0 && J % 2 == 0) || (L != 0 && L % 2 == 0)) K -= 4;
    }

    cout << K / 2 << endl;


    return 0;
}