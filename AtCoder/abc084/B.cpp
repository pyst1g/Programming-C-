// finish date: 2018/01/02
#include <iostream>
#include <typeinfo>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define REP(i, n)  FOR(i,0,n)

int main() {
    int A, B;
    string M;
    cin >> A >> B;
    cin >> M;
    string str = "Yes";

    REP(i, M.length()) {
        if (i == A) {
            if (M[i] != '-') {
                str = "No";
                break;
            }
        } else {
            if (!('0' <= M[i] && M[i] <= '9')) {
                str = "No";
                break;
            }
        }
    }
    if(M.length() != A+B+1) str= "No";
    cout << str;
}