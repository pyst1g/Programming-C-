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

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = ans * i;
    }
    return ans;
}

vector<int> a;
vector<int> b;
vector<vector<int>> path;
vector<bool> isPassed;
int N;

int calc(int pos = 0, int depth = 1) {
    if (depth == N) return 1;
    int nextpos;
    int sum=0;
    rep(i,path[pos].size()){
        nextpos = path[pos][i];
        if(isPassed[nextpos]) continue;
        isPassed[nextpos]=true;
        sum += calc(nextpos,depth+1);
        isPassed[nextpos]=false;
    }
    return sum;
}


int main() {
    int M;
    cin >> N >> M;
    a = vector<int>(M);
    b = vector<int>(M);
    path = vector<vector<int>>(N);
    isPassed = vector<bool>(N, false);
    isPassed[0] = true;

    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--;
        b[i]--;
        path[a[i]].emplace_back(b[i]);
        path[b[i]].emplace_back(a[i]);
    }
    cout << calc() << endl;

    return 0;
}
