// finish date: 2018/02/20
#include <iostream>
#include <cmath>
#include <vector>
#include <bitset>
#include <algorithm>
#include <stack>
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
#define bigmod 1000000007
#define INF 500000000


class StonesOnATreeDiv2 {
public:
    int minStones(vector<int> p, vector<int> w) {
        int N = w.size();
        vi parent(N);
        vb haveChild(N, false);
        vi height(N);
        parent[0] = 0;
        height[0] = 1;
        int maxheight = 0;
        rep(i, N - 1) {
            parent[i + 1] = p[i];
            height[i + 1] = height[p[i]] + 1;
            maxheight = max(maxheight,height[i+1]);
            haveChild[p[i]] = true;
        }
        int mi = INF;


        int wei = 0;
        int mawei = 0;
        rep(i,N){
            if(height[i]==1) wei+=w[i];
            else if(height[i]%2==0&&(haveChild[i]||maxheight==2)) wei+=w[i];
            else mawei = max(mawei,w[i]);
        }

        return wei+mawei;
    }


};

