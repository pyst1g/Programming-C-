// finish date: 2018/01/08
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int N, H;
    cin >> N >> H;
    vector<int> a(N);
    vector<int> b(N);

    rep(i, N) cin >> a[i] >> b[i];
    int maxa = 0;
    rep(i, N) if (a[i] > maxa) maxa = a[i];
    int count = 0;
    sort(b.begin(), b.end(), greater<int>());
    rep(i, N) {
        if (b[i] > maxa) {
            H -= b[i];
            count++;
            if (H <= 0) {
                cout << count << endl;
                return 0;
            }
        }else{
            break;
        }
    }
    count += (H + maxa - 1) / maxa;
    cout << count << endl;
    return 0;
}
