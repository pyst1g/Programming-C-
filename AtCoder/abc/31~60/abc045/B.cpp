// finish date: 2018/01/10
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

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

int main() {
    vector<string> S(3);
    cin >> S[0] >> S[1] >> S[2];
    vector<int> indice(3, 0);
    char c = 'a';
    while (true) {
        if (indice[c - 'a'] == S[c - 'a'].length()) {
            cout << (char) ('A' + c - 'a') << endl;
            break;
        }
        indice[c - 'a']++;
        c = S[c-'a'][indice[c-'a']-1];

    }


    return 0;
}