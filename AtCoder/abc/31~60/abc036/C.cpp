// finish date: 2018/01/17
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
    vector<int> a(N);
    map<int, int> mp;
    rep(i, N) {
        cin >> a[i];
        mp[a[i]] = 0;
    }
    int count = 0;
    for (auto e:mp) {
        mp[e.first] = count;
        count++;
    }
    rep(i, N) cout << mp[a[i]]<<endl;

    return 0;
}
