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
    int N, M;
    cin >> N >> M;
    vi to;
    map<int, int> mp;
    int a, b;
    rep(i, M) {
        cin >> a >> b;
        if (a == 1) to.push_back(b);
        if (b == N) mp[a] = 1;
    }
    rep(i,to.size()){
        if(mp.count(to[i])!=0){
            cout<<"POSSIBLE"<<endl;
            return 0;
        }
    }
    cout<<"IMPOSSIBLE"<<endl;


    return 0;
}

