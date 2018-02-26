// finish date: 2018/01/21
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
    vector<ll> lucas(N + 1);
    lucas[0] = 2;
    lucas[1] = 1;
    FOR(i, 2, N + 1) lucas[i] = lucas[i - 1] + lucas[i - 2];
    cout << lucas[N] << endl;

    return 0;
}
