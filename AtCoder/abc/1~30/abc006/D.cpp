// finish date: 2018/01/23
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
#define vl vector<ll>
#define bigmod 1000000007
#define INF 500000000

vi c, lis;

int bs(int n) {
    int l = 0, r = lis.size() - 1;
    int m;
    while (true) {
        m = (l + r) / 2;
        if (lis[m] < n && n <= lis[m + 1]) {
            return m;
        } else if (lis[m] < n) {
            l = m + 1;
        } else {
            r = m;
        }
    }

}

int main() {
    int N;
    cin >> N;
    c = vi(N);
    lis = vi(N + 1, INF);
    lis[0] = -INF;
    rep(i, N) cin >> c[i];
    int pos;
    rep(i, N) {
        pos = bs(c[i]);
        lis[pos + 1] = min(lis[pos + 1], c[i]);
    }
    for(int i=lis.size()-1;i>=1;i--){
        if(lis[i]!=INF){
            cout<<c.size()-i<<endl;
            break;
        }
    }
    return 0;
}

