// finish date: 2018/05/02

//#include <bits/stdc++.h>
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
#include <map>
#include <climits>
#include <queue>

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
    priority_queue<ll, vector<ll>, greater<ll>> pq;
    rep(i, N) {
        int L;
        cin >> L;
        pq.push(L);
    }
    ll cost = 0;
    while (pq.size() > 1) {
        ll l1, l2;
        l1 = pq.top();
        pq.pop();
        l2 = pq.top();
        pq.pop();
        pq.push(l1 + l2);
        cost += l1 + l2;
    }
    cout << cost << endl;


    return 0;
}