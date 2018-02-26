// finish date: 2018/01/02
#include <iostream>
#include <typeinfo>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

int main() {
    int N;
    cin >> N;
    int CSF[N-1][3];
    int time;
    rep(i, N - 1) {
        cin >> CSF[i][0] >> CSF[i][1] >> CSF[i][2];
    }
    rep(i, N - 1) {
        time = 0;
        FOR(j, i, N - 1) {
            int a = (int) (time + CSF[j][2] - 1 / CSF[j][2]);
            time = max(CSF[j][1], CSF[j][2] * (int) ((time + CSF[j][2] - 1 )/ CSF[j][2]))+CSF[j][0];
        }
        cout << time << endl;
    }
    cout << 0 << endl;
    return 0;
}