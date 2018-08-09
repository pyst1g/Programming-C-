// finish date: 2018/01/19
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
    int sum, mi=INF;
    vector<int> a(N);
    rep(i, N) cin >> a[i];
    FOR(i,-100,101){
        sum = 0;
        rep(j,N){
            sum += (i-a[j])*(i-a[j]);
        }
        mi = min(mi,sum);
    }
    cout<<mi<<endl;

    return 0;
}
