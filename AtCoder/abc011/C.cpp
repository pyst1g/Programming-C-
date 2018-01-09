// finish date: 2018/01/09
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
    int NG[3];
    cin >> N >> NG[0] >> NG[1] >> NG[2];
    sort(NG, NG + 3, greater<int>());
    rep(i, 3) {
        if (N == NG[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    int n;
    int count = 0;
    while (true) {
        n = N-3;
        if (n == NG[0] || n == NG[1] || n == NG[2]) {
            n++;
            if (n == NG[0] || n == NG[1] || n == NG[2]){
                n++;
                if (n == NG[0] || n == NG[1] || n == NG[2]){
                    cout<<"NO"<<endl;
                    break;
                }
            }
        }
        N=n;
        count++;
        if(count>100){
            cout<<"NO"<<endl;
            break;
        }else if(N<=0){
            cout<<"YES"<<endl;
            break;
        }
    }

    return 0;
}



