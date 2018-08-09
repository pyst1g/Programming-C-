// finish date: 2018/01/20
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

string changeBase(int N, int b, int digit = -1) {
    string s = "";
    while (N != 0) {
        s = to_string(N % b) + s;
        N /= b;
    }
    if (digit != -1) {
        while (s.length() < digit) {
            s = "0" + s;
        }
    }
    return s;
}

int main() {
    string S;
    cin >> S;
    ll sum = 0;
    string isPlus;
    string str;
    ll temp;
    rep(i, pow(2, S.length() - 1)) {
        str = S[0];
        isPlus = changeBase(i, 2, S.length() - 1);
        rep(j, isPlus.length()) {
            if (isPlus[j] == '1') str += "+";
            str += S[j + 1];
        }
        //cout<<str<<endl;
        temp = 0;
        rep(k, str.length()) {
            if (str[k] == '+') {
                sum += temp;
                temp = 0;
            } else {
                temp *= 10;
                temp += str[k] - '0';
            }
            if (k == str.length() - 1) sum += temp;
        }
    }
    cout << sum << endl;

    return 0;
}
