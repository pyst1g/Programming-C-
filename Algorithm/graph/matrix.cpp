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
#define vl vector<ll>
#define vvl vector<vector<ll>>
#define vb vector<bool>
#define vvb vector<vector<bool>>
#define vc vector<char>
#define vvc vector<vector<char>>
#define vs vector<string>
#define bigmod 1000000007
#define INF 1050000000


void around9(vvi v, int i, int j) {
    vector<pair<int, int>> xy;
    xy.push_back(make_pair(i,j));
    if (j > 0) xy.push_back(make_pair(i, j - 1));
    if (j + 1 < v[0].size()) xy.push_back(make_pair(i, j + 1));
    if (i > 0) {
        xy.push_back(make_pair(i - 1, j));
        if (j > 0) xy.push_back(make_pair(i - 1, j - 1));
        if (j + 1 < v[0].size()) xy.push_back(make_pair(i - 1, j + 1));
    }
    if (i + 1 < v.size()) {
        xy.push_back(make_pair(i + 1, j));
        if (j > 0) xy.push_back(make_pair(i + 1, j - 1));
        if (j + 1 < v[0].size()) xy.push_back(make_pair(i + 1, j + 1));
    }

    //ここからやりたい処理を書く
    for (auto p: xy){

    }
}