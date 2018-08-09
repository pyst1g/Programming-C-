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

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define bigmod 1000000007
#define INF 500000000

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> s(N);
    rep(i, N) {
        cin >> s[i];
        if (s[i] == 0) {
            cout << N << endl;
            return 0;
        }
    }
    ll pro = 1;
    int lpos = 0;
    int max_length = 0;
    rep(i, N) {
        pro *= s[i];
        if (pro > K) {
            if (lpos == i) {
                pro = 1;
                lpos++;
                continue;
            } else {
                while(pro>K) {
                    pro /= s[lpos];
                    lpos++;
                }
            }
        }
        max_length = max(max_length, i - lpos + 1);
    }
    cout << max_length << endl;

    return 0;
}
