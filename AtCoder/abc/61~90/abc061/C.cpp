// finish date: 2018/01/22
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
    ll K;
    cin >> N >> K;
    map<int, ll> mp;
    int a, b;
    rep(i, N) {
        cin >> a >> b;
        mp[a] += b;
    }
    ll sum = 0;
    for(auto itr:mp){
        sum+=itr.second;
        if(sum>=K){
            cout<<itr.first<<endl;
            return 0;
        }
    }

    return 0;
}

