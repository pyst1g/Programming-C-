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
    vector<int> a(N);
    vector<bool> isPushed(N, false);
    rep(i, N) {
        cin >> a[i];
        a[i]--;
    }
    int pos = 0;
    int count = 0;
    while (!isPushed[pos]) {
        if (pos == 1) {
            cout << count << endl;
            return 0;
        }
        isPushed[pos] = true;
        pos = a[pos];
        count++;
    }

    cout << -1 << endl;


    return 0;
}
