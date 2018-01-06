// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <limits>
#include <map>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

bool isExist(char c, string str) {
    rep(i, str.length()) {
        if (c == str[i]) return true;
    }
    return false;
}

int main() {
    int N;
    vector<int> C;
    vector<vector<int>> mul(100,vector<int>(100));
    double exp; //expected value

    cin >> N;
    C.assign(N,0);
    rep(i,N) cin >> C[i];
    sort(C.begin(),C.end());
    rep(i,N){
        rep(j,mul.size()){
            if(C[i]%mul[j][0]==0) mul[j].push_back(C[i]);
            goto outer;
        }
        mul.emplace_back({C[i]});
        outer:;
    }
    printf("%.6f\n",exp);
    return 0;
}
