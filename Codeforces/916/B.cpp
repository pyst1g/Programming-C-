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
    ll n;
    int k;
    cin >> n >> k;
    map<int, int> mp;
    while (n != 0) {
        int i = 62;
        while ((ll) pow(2, i) > n) i--;
        mp[i]++;
        k--;
        n -= (ll) pow(2, i);
    }
    if (k < 0) {
        cout << "No" << endl;
        return 0;
    }
    auto itr = mp.rbegin();
    //yminを確定する作業
    while (itr->second <= k) {
        mp[itr->first - 1] += itr->second * 2;
        k -= itr->second;
        itr->second = 0;
        itr++;
    }
    //lexicographicallyにする作業
    while (k != 0) {
        mp.begin()->second--;
        mp[mp.begin()->first - 1]+=2;
        k--;
    }

    cout << "Yes" << endl;
    for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
        int sec = itr->second;
        rep(i, sec) {
            cout << itr->first<<" ";
        }

    }
    cout << endl;

    return 0;
}
