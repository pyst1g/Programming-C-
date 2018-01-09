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
    int N;
    cin >> N;
    vector<int> a(N);
    int sum = 0;
    int hasiCount = 0;
    rep(i, N) {
        cin >> a[i];
        sum += a[i];
    }
    int ave = sum / N;
    if (sum % N != 0) cout << -1 << endl;
    else {
        sum = 0;
        int s = 0;
        rep(i, N) {
            sum += a[i];
            s++;
            if ((double) sum / s == ave) { // sum/sの小数点を切り上げる
                sum = 0;
                s = 0;
            } else {
                hasiCount++;
            }
        }

        cout << hasiCount << endl;
    }

    return 0;
}
