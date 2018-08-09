// finish date: 2018/01/20
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


int main() {
    int N, M;
    cin >> N >> M;
    map<int, int> mp;
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        a--;
        b--;
        mp[a]++;
        mp[b]++;
    }
    rep(i, N) cout << mp[i] << endl;


    return 0;
}
