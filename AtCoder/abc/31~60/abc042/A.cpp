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
    int A, B, C;
    cin >> A >> B >> C;
    if((A==5&&B==5)||(B==5&&C==5)||(C==5&&A==5)){
        if(A==7||B==7||C==7){
            cout <<"YES"<<endl;
            return 0;
        }
    }
    cout<<"NO"<<endl;


    return 0;
}
