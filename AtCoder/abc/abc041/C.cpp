// finish date: 2018/01/18
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
    int in;
    vector<pair<int, int>> a(N);
    rep(i, N) {
        cin >> in;
        a[i] = make_pair(in, i + 1);
    }
    sort(a.begin(), a.end(), greater<pair<int,int>>());
    rep(i, N) cout << a[i].second << endl;
    return 0;
}
