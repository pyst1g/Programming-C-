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
    int N, A, B;
    cin >> N >> A >> B;
    int n, sum;
    int ans=0;
    rep(i, N+1) {
        n = i;
        sum = 0;
        while (n != 0) {
            sum += n % 10;
            n /= 10;
        }
        if (A <= sum && sum <= B) ans+=i;
    }
    cout << ans << endl;

    return 0;
}
