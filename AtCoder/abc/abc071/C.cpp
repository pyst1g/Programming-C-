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
    ll S = 0;
    map<int, int> mp;
    int A;
    rep(i, N) {
        cin >> A;
        mp[A]++;
    }
    int l1 = 0, l2 = 0;
    for (auto itr = mp.rbegin(); itr != mp.rend(); itr++) {
        if(itr->second>=4){
            l1 = max(l1,itr->first);
            l2 = itr->first;
            break;
        }
        if (itr->second >= 2) {
            if (l1 == 0) l1 = itr->first;
            else {
                l2 = itr->first;
                break;
            }
        }
    }
    S = (ll) l1 * l2;
    cout << S << endl;


    return 0;
}

