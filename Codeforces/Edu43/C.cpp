// finish date: 2018/04/30

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

struct lr {
    int L, R, index;
};


int main() {
    int n;
    cin >> n;
    vector<lr> LR(n);
    rep(i, n) {
        int l, r;
        cin >> l >> r;
        LR[i] = {l, r, i + 1};
    }

    sort(LR.begin(), LR.end(),
         [](const lr &a, const lr &b) { return a.R < b.R; });
    rep(i, n - 1) {
        if (LR[i].R == LR[i + 1].R) {
            if (LR[i].L >= LR[i + 1].L) cout << LR[i].index << " " << LR[i + 1].index << endl;
            else cout << LR[i + 1].index << " " << LR[i].index << endl;
            return 0;
        }
    }

    sort(LR.begin(), LR.end(),
         [](const lr &a, const lr &b) { return a.L < b.L; });
    rep(i, n - 1) {
        if (LR[i].L == LR[i + 1].L) {
            if (LR[i].R <= LR[i + 1].R) cout << LR[i].index << " " << LR[i + 1].index << endl;
            else cout << LR[i + 1].index << " " << LR[i].index << endl;
            return 0;
        }
    }
    vi mi(n);
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) mi[i] = INF;
        else mi[i] = min(mi[i + 1], LR[i+1].R);
    }
    rep(i, n) {
        if (mi[i] <= LR[i].R) {
            FOR(j, i + 1, n) {
                if (LR[j].R == mi[i]) {
                    cout << LR[j].index << " " << LR[i].index << endl;
                    return 0;
                }
            }
        }
    }
    cout << -1 << " " << -1 << endl;

    return 0;
}