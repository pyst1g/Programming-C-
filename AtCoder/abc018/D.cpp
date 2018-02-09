// finish date: 2018/02/09

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>


struct choco {
    int men, h;
};

int main() {
    int N, M, P, Q, R;
    cin >> N >> M >> P >> Q >> R;
    vector<vector<choco>> f(N, vector<choco>());
    int x, y, z;
    rep(i, R) {
        cin >> x >> y >> z;
        x--;
        y--;
        f[x].push_back({y, z});
    }

    int temp;
    int ma = 0;
    rep(i, 1 << N) {
        if (__builtin_popcount(i) != P) continue;
        vi sum(M, 0);
        temp = 0;
        rep(j, N) {
            if (!(i >> j & 1)) continue;
            rep(k,f[j].size()){
                sum[f[j][k].men] += f[j][k].h;
            }
        }
        sort(sum.begin(),sum.end(),greater<int>());
        rep(k,Q) temp += sum[k];
        ma = max(ma,temp);
    }
    cout<<ma<<endl;


    return 0;
}


