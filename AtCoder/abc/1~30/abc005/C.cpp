// finish date: 2018/01/05
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>

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
    int T, N, M;
    vector<int> A, B;
    cin >> T >> N;
    A.reserve(N);
    rep(i, N) cin >> A[i];
    cin >> M;
    B.reserve(M);
    rep(i, M) cin >> B[i];
    int pos = 0;
    rep(i,N){
        if(A[i] <= B[pos] && B[pos] <= A[i]+T){
            pos++;
            if(pos == M){
                cout << "yes" << endl;
                return 0;
            }
        }
    }
    cout << "no" << endl;
    return 0;
}
