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
    int n = N;
    int sum = 0;
    while (n != 0) {
        sum += n % 10;
        n /= 10;
    }
    if (N % sum == 0) cout << "Yes" << endl;
    else cout << "No" << endl;

    return 0;
}
