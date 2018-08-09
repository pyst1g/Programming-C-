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
    map<int, int> mp;
    int A;
    rep(i, N) {
        cin >> A;
        if (mp.count(A)) mp.erase(A);
        else mp[A] = 1;
    }
    cout << mp.size() << endl;

    return 0;
}

