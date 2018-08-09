// finish date: 2018/01/22
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
#define bigmod 1000000007
#define INF 500000000


ll calc(int i, int j, int bi) {
    ll mi = LONG_LONG_MAX;
    ll S1, S2, S3;
    S1 = (ll)(i / 3 + bi) * j;
    S2 = (ll)(i - (i / 3 + bi)) * (j / 2);
    S3 = (ll)j * i - S1 - S2;
    mi = min(mi, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
    S2 = (ll)j * ((i - (i / 3 + bi)) / 2);
    S3 = (ll)j * i - S1 - S2;
    mi = min(mi, max(S1, max(S2, S3)) - min(S1, min(S2, S3)));
    return mi;
}

int main() {
    int H, W;
    cin >> H >> W;
    if (H % 3 == 0 || W % 3 == 0) {
        cout << 0 << endl;
        return 0;
    }
    ll mi1 = min(calc(H,W,0),calc(H,W,1));
    ll mi2 = min(calc(W,H,0),calc(W,H,1));
    cout<<min(mi1,mi2)<<endl;


    return 0;
}

