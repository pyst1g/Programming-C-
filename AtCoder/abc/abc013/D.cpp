// finish date: 2018/02/07

#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <climits>

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

struct hw {
    int h, w;
};


int main() {
    int N, M, D;
    cin >> N >> M >> D;
    vi goal(N, 0);
    rep(i, N) goal[i] = i;
    int A;
    rep(k, M) {
        cin >> A;
        A--;
        swap(goal[A], goal[A + 1]);
    }
    //阿弥陀1回の遷移先を保存
    map<int, int> move;
    rep(i, N) move[goal[i]] = i;
    vector<hw> group(N);

    //阿弥陀を複数回つなげた場合の遷移を求める
    vb isLoop(N, false);
    vvi Loop(N);
    int i;
    rep(k, N) {
        i = k;
        if (isLoop[k]) continue;
//        isLoop[k] = true;
        while (!isLoop[i]) {
            Loop[k].push_back(i);
            group[i].h = k;
            group[i].w = Loop[k].size() - 1;
            isLoop[i] = true;
            i = move[i];
        }
    }
    rep(i, N) {
        cout << Loop[group[i].h][(D + group[i].w) % Loop[group[i].h].size()]+1 << endl;
    }


    return 0;
}


