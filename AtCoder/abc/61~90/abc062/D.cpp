// finish date: 2018/03/13

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


int main() {
    int N;
    cin >> N;
    map<int, int> A, B;
    vi arr(N);
    int in;
    vl sumA(N + 1, 0), sumB(N + 1, 0);
    rep(i, N) {
        cin >> in;
        A[in]++;
        sumA[0] += in;
    }
    rep(i, N) {
        cin >> arr[i];
    }
    rep(i, N) {
        cin >> in;
        B[in]++;
        sumB[0] += in;
    }

    rep(i, N) {
        sumA[i + 1] = sumA[i] + max(arr[i], A.begin()->first) - A.begin()->first;
        if (arr[i] > A.begin()->first) {
            A[arr[i]]++;
            A.begin()->second--;
            if (A.begin()->second == 0) A.erase(A.begin()->first);
        }

        sumB[i + 1] = sumB[i] + min(arr[N - 1 - i], B.rbegin()->first) - B.rbegin()->first;
        if (arr[N - 1 - i] < B.rbegin()->first) {
            B[arr[N - 1 - i]]++;
            B.rbegin()->second--;
            if (B.rbegin()->second == 0) B.erase(B.rbegin()->first);
        }
    }

    ll ma = LONG_LONG_MIN;
    rep(i, N + 1) {
        ma = max(ma, sumA[i] - sumB[N-i]);
    }
    cout<<ma<<endl;

    return 0;
}