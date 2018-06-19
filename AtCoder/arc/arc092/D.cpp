// finish date: 2018/05/13
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
    vi a(N), b(N);
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];
    vi count(30, 0);
    vl v(N);
    rep(i, 30) {
        rep(j, N) {
            v[j] = (int) (b[j] % ((ll) 1 << (i + 1)));
        }
        sort(v.begin(), v.end());
        rep(j, N) {
            int Tmin = (1 << i) - (int) (a[j] % ((ll) 1 << (i + 1)));
            int Tmax = (1 << (i + 1)) - (int) (a[j] % ((ll) 1 << (i + 1)));
//            cout << distance(lower_bound(v.begin(), v.end(), Tmin),
//                             lower_bound(v.begin(), v.end(), Tmax)) << " " <<
//                 distance(lower_bound(v.begin(), v.end(), Tmin + (1 << (i + 1))),
//                          lower_bound(v.begin(), v.end(), Tmax + (1 << (i + 1)))) << endl;
            count[i] = (count[i] +
                        distance(lower_bound(v.begin(), v.end(), Tmin),
                                 lower_bound(v.begin(), v.end(), Tmax)) +
                        distance(lower_bound(v.begin(), v.end(), (ll)Tmin + (1 << (i + 1))),
                                 lower_bound(v.begin(), v.end(), (ll)Tmax + (1 << (i + 1)))))
                       % 2;
        }
    }
    int ans = 0;
    rep(i, 30) {
        ans += count[i] << i;
    }
    cout << ans << endl;
    return 0;
}