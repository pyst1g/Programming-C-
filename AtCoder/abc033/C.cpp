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
    string S;
    cin >> S;
    int count = 1;
    bool already0 = false;
    rep(i, S.length()) {
        if (S[i] == '+') {
            count++;
            already0 = false;
        } else if (S[i] == '0') {
            if (!already0) count--;
            already0 = true;
        }
    }
    cout << count << endl;
    return 0;
}
