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


struct Simple_Tree {
    vector<int> node;
    vector<int> parent;
    vector<int> height;

    Simple_Tree(int n) : node(n), parent(n), height(n) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    // 高さの更新 O(N)
    void update_height() {
        height = vi(height.size(), 0); //この0は再帰の部分で生きるので変えてはいけない
        for (int i = 0; i < height.size(); i++) update_height_memo(i);
    }

    int update_height_memo(int i) {
        if (height[i] != 0) return height[i];
        if (i == parent[i]) {
            height[i] = 0;
            return height[i];
        }
        height[i] = update_height_memo(parent[i]) + 1;
    }


    void make_edge(int a, int b) {
        parent[b] = a;
    }
};


int main() {
    int N;
    cin >> N;
    Simple_Tree tree(N);
    int x, y;
    rep(i, N - 1) {
        cin >> x >> y;
        x--;
        y--;
        tree.make_edge(x, y);
    }
    tree.update_height();

    int Q;
    cin >> Q;
    int a, b;
    rep(i, Q) {
        cin >> a >> b;
        cout<<tree.height[a]+tree.height[b]+1<<endl;
    }

    return 0;


}



