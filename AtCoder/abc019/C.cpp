// finish date: 2018/01/10
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

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int fact(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans *= i;
    }
    return ans;
}

int main() {
    int N;
    cin >> N;
    vector<int> a(N,0);
    vector<int> b(N,0);
    map<int,int> mp;

    rep(i, N) cin >> a[i];
    sort(a.begin(), a.end());
    rep(i,N) while(a[i]%2==0) a[i]/=2;
    rep(i,N) mp[a[i]]=0;

    cout << mp.size() << endl;
    return 0;
}