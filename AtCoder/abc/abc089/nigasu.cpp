// finish date: 2018/03/02

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
    int V = 7;
    vector<vector<pii>> edge(V,vector<pii>());
    edge[0].emplace_back(pii(4,1));
    edge[0].emplace_back(pii(5,2));
    edge[0].emplace_back(pii(2,4));
    edge[1].emplace_back(pii(4,0));
    edge[1].emplace_back(pii(6,2));
    edge[1].emplace_back(pii(4,3));
    edge[1].emplace_back(pii(3,4));
    edge[2].emplace_back(pii(5,0));
    edge[2].emplace_back(pii(6,1));
    edge[2].emplace_back(pii(6,3));
    edge[2].emplace_back(pii(10,6));
    edge[2].emplace_back(pii(3,4));
    edge[3].emplace_back(pii(4,1));
    edge[3].emplace_back(pii(6,2));
    edge[3].emplace_back(pii(6,4));
    edge[3].emplace_back(pii(2,5));
    edge[3].emplace_back(pii(6,6));
    edge[4].emplace_back(pii(2,0));
    edge[4].emplace_back(pii(3,1));
    edge[4].emplace_back(pii(6,3));
    edge[4].emplace_back(pii(9,5));
    edge[5].emplace_back(pii(2,3));
    edge[5].emplace_back(pii(9,4));
    edge[5].emplace_back(pii(3,6));
    edge[6].emplace_back(pii(10,2));
    edge[6].emplace_back(pii(6,3));
    edge[6].emplace_back(pii(3,5));
    rep(i,V){
        rep(j,edge[i].size()){
            edge[i].push_back(pii(edge[i][j].second,edge[i][j].first));
            edge[i].erase(edge[i].begin());
        }
    }
    vi dist = dijkstra(0,7,edge);

    return 0;
}



//
// Created by local-user on 2018/03/04.
//

