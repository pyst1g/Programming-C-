// finish date: 2018/02/10

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

struct edge {
    int from, to;
    ll distance;
};

struct CompareEdgeByDistance {
    bool operator()(edge &a, edge &b) {
        return a.distance < b.distance;
    }
};


vl dijkstra(int start, vector<edge> e, int S) {
    vb isMinDis(S, false);
    vvi goal(S, vi());
    vvl distance(S, vl());
    vl result(S, LONG_LONG_MAX);
    rep(i, S) {
        goal[e[i].from].push_back(e[i].to);
        distance[e[i].from].push_back(e[i].distance);
    }
    priority_queue<edge, vector<edge>, CompareEdgeByDistance> pq;

    edge tempE;
    rep(i, goal[start].size()) {
        tempE.from = start;
        tempE.to = goal[start][i];
        tempE.distance = distance[start][i];
        pq.push(tempE);
    }
    isMinDis[start] = true;
    result[start] = 0;

    edge minEdge;
    int count = 0;
    while (count <= S) {
        minEdge = pq.top();
        pq.pop();
        if (isMinDis[minEdge.to]) continue;
        result[minEdge.to] = min(result[minEdge.to], result[minEdge.from] + minEdge.distance);

        count++;
        isMinDis[minEdge.to] = true;
        pq.push()


    }


}


int main() {
    int N, M, T;
    cin >> N >> M >> T;
    vi A(N);
    rep(i, N) cin >> A[i];
    vector<edge> e1(M), e2(M);
    int a, b, c;
    rep(i, M) {
        cin >> a >> b >> c;
        a--;
        b--;
        //順方向
        e1[i].from = a;
        e1[i].to = b;
        e1[i].distance = c;
        //逆方向
        e2[i].from = b;
        e2[i].to = a;
        e2[i].distance = c;

    }
    priority_queue<edge, vector<edge>, CompareEdgeByDistance> pq1, pq2;


    return 0;
}


