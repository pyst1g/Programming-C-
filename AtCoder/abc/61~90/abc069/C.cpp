// finish date: 2018/01/23
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
#define vi vector<int>
#define vl vector<ll>
#define bigmod 1000000007
#define INF 500000000


int main() {
    int N;
    cin >> N;
    int a;
    int count2 = 0, count4 = 0, counte = 0;
    rep(i, N) {
        cin >> a;
        if (a % 4 == 0) count4++;
        else if (a % 2 == 0) count2++;
        else counte++;
    }
    N -= count2;
    if (count4 >= counte) cout << "Yes" << endl;
    else if (count2 == 0 && count4 >= counte - 1) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}

