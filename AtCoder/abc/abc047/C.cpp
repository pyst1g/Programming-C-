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


int main() {
    string S;
    cin >> S;
    char col=' ';
    int count = 0;
    rep(i, S.length()) {
        if(i==0){
            col = S[i];
            continue;
        }
        if (S[i] != col) {
            count++;
        }
        col = S[i];
    }
    cout << count << endl;
    return 0;
}
