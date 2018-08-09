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


int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    int a;
    rep(i, N) {
        cin >> a;
        mp[min(8, a / 400)]++;
    }
    int mi, ma;
    mi = max(1,(int)mp.size() - ((mp.count(8)) ? 1 : 0));
    ma = min(mi + mp[8], 8);

    cout << mi << " " << ma << endl;

    return 0;
}

