// finish date: 2018/03/18

#include <bits/stdc++.h>

using namespace std;

#define FOR(i, a, b) for(int (i)=a;(i)<(b);(i)++)
#define rep(i, n)  FOR(i,0,n)
#define ll long long
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


int main() {
    int N;
    cin >> N;
    vl a(N);
    ll maxVal = -LONG_LONG_MAX;
    int maxIndex;
    rep(i, N) {
        cin >> a[i];
        if (maxVal < a[i]) {
            maxVal = a[i];
            maxIndex = i;
        }
    }
    if (N == 2) {
        cout << max(a[0], a[1]) << endl;
        cout << 1 << endl;
        if (a[0] > a[1]) cout << 2 << endl;
        else cout << 1 << endl;
        return 0;
    }
    if (maxVal <= 0) {
        cout << maxVal << endl;
        cout << N - 1 << endl;
        for (int i = N; i >= maxIndex + 2; i--) {
            cout << i << endl;
        }
        rep(i, maxIndex) {
            cout << 1 << endl;
        }
        return 0;
    }


    ll oddMax = 0;
    ll evenMax = 0;
    rep(i, N) {
        if (i % 2 == 0) oddMax += max(a[i], (ll) 0);
        else evenMax += max(a[i], (ll) 0);
    }
    vi operate;
    int l, r;
    if (oddMax > evenMax) l = 0;
    else {
        operate.emplace_back(0);
        l = 1;
    }
    r = l + 1;

    while (l + 1 < N) {
        if (r + 1 >= N) {
            operate.emplace_back(1);
            break;
        }
        if (a[l] < 0) {
            operate.emplace_back(0);
            operate.emplace_back(0);
            l += 2;
            r = l + 1;
        } else if (a[r + 1] < 0) {
            operate.emplace_back(2);
            if (r + 2 >= N) {
                operate.emplace_back(1);
                break;
            }
            r += 2;

        } else {
            operate.emplace_back(1);
            a[r + 1] += a[l];
            l = r + 1;
            r = l + 1;
        }

    }

    cout << max(evenMax, oddMax) << endl;
    cout << operate.size() << endl;
    rep(i, operate.size()) {
        cout << operate[i] + 1 << endl;
    }


    return 0;
}

