// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)


int main() {
    int N, M;
    int x, y;
    cin >> N >> M;
    vector<vector<int>> fs(N, vector<int>(N,0));
    rep(i, M) {
        cin >> x >> y;
        fs[x - 1][y - 1] = fs[y - 1][x - 1] = 1;
    }
    bitset<12> b;
    vector<int> check;
    //check.push_back(1);
    int maxnum = 0;
    rep(i, (int) pow(2, N)) {
        check.clear();
        b = bitset<12>(i);
        rep(j,N) {
            if (b.test(j)) {
                check.push_back(j);
            }
        }
        /*
        if(check.size()==4) {
            cout <<b <<endl;
            int a = 0;
        }*/
        if (check.size() < maxnum) goto loopend;
        rep(j, check.size()) {
            FOR(k, j+1, check.size()) {
                if(j==k) continue;
                if (!fs[check[j]][check[k]]) goto loopend;
            }
        }
        maxnum = max(maxnum, (int) check.size());
        loopend:;
    }
    cout << maxnum << endl;
}
