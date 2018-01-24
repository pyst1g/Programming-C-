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


int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    int N;
    cin >> N;
    map<int, int> mp;
    FOR(i, 2, N + 1) {
        int n = i;
        int j = 2;
        while (n != 1) {
            if (n % j == 0) {
                mp[j]++;
                n /= j;
            } else j++;
        }
    }
    int ans = 1;
    for (auto itr:mp) ans = mul(ans, itr.second + 1);

    cout << ans << endl;

    return 0;
}
