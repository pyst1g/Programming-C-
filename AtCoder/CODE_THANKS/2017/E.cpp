// finish date: 2018/04/25

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll double
#define vi vector<int>
#define vvi vector<vector<int>>
#define vvvi vector<vector<vector<int>>>
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vd vector<double>
#define vvd vector<vector<double>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vs vector<string>
#define vc vector<char>
#define vvc vector<vector<char>>
#define bigmod 1000000007
#define INF 1050000000
#define pii pair<int,int>

string changeBase(int N, int b, int digit = -1) {
    string s = "";
    while (N != 0) {
        s = to_string(N % b) + s;
        N /= b;
    }
    if (digit != -1) {
        while (s.length() < digit) {
            s = "0" + s;
        }
    }
    return s;
}

int main() {
    int N;
    cin >> N;
    int M = (N + 4) / 5 * 5;
    vi ans(M, 0);
    for (int i = 1; i <= M; i += 5) {

        cout << "?" << " ";
        int weight = 0;
        FOR(j, 1, N + 1) {
            if (i <= j && j < i + 5) {
                cout << (int) (pow(5, 4 - (j - 1) % 5) + 0.5) << " ";
                weight -= (int) (pow(5, 4 - (j - 1) % 5) + 0.5) * 8;
            } else cout << 0 << " ";
        }
        cout << endl;
        int w;
        cin >> w;
        weight += w;

        string weight_to_5 = changeBase(weight, 5, 5);
        FOR(j, i, i + 5) {
            ans[j - 1] = (weight_to_5[(j - 1) % 5] - '0' == 1 || weight_to_5[(j - 1) % 5] - '0' == 3);
        }
    }
    cout << "! ";
    rep(i, N) {
        cout << ans[i] << " ";
    }
    cout << endl;

    return 0;
}