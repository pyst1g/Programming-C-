// finish date: 2018/01/11
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>

#define bigmod 1000000007
using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long

int mul(int a, int b) {
    return (int) (((ll) (a % bigmod) * (b % bigmod)) % bigmod);
}

int factorial(int n) {
    int ans = 1;
    FOR(i, 1, n + 1) {
        ans = mul(ans, i);
    }
    return ans;
}

int main() {
    int N, M;
    cin >> N >> M;
    vector<string> A(N);
    vector<string> B(N);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    if (N < M) {
        cout << "No" << endl;
        return 0;
    }
    rep(i,N-M+1){
        rep(j,N-M+1){
            rep(k,M){
                rep(l,M){
                    if(B[k][l] != A[i+k][j+l]){
                        goto next;
                    }
                    if(k==M-1&&l==M-1){
                        cout<<"Yes"<<endl;
                        return 0;
                    }
                }
            }
            next:;
        }
    }
    cout <<"No"<<endl;


    return 0;
}
