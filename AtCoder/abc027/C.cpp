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
#define INF 1000000000


int main() {
    ll N;
    cin >> N;
    N++;
    ll x = 1;
    int turn = 0;
    bool isRight = ((int) log2(N) % 2 == 0) ? true : false;
    while (x < N) {
        if (isRight) x = x * 2 + 1;
        else x = x * 2;
        isRight = !isRight;
        turn++;
    }
    if (turn % 2 == 0) cout << "Takahashi" << endl;
    else cout << "Aoki" << endl;


    return 0;
}
