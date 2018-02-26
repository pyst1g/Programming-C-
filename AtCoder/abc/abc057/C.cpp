// finish date: 2018/01/15
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

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int main() {
    ll N;
    cin >> N;
    int s = (int) sqrt(N);
    int ma_ab=1; //代入する値は適当
    for (int i = s; i >= 1; i--) {
        if (N % i == 0) {
            ma_ab = (i > N / i) ? i : (int)(N / i);
            break;
        }
    }
    cout << (int) log10(ma_ab) + 1 << endl;


    return 0;
}
