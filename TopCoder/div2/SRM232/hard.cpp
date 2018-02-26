// finish date: 2018/02/19

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


vi split(string prices) {
    int s = 0;
    vi ret;
    ret.reserve(50);
    rep(i, prices.length()) {
        if (prices[i] == ' ' || i == prices.length() - 1) {
            ret.push_back(stoi(prices.substr(s, i - s + 1)));
            s = i;
        }
    }
    return ret;
}

int maximumEarnings(int initialInvestment, int monthlyContribution, vector<string> stockPrices) {
//    if (stockPrices.size() == 1) return 0;
    int N = split(stockPrices[0]).size();
    int monthNum = stockPrices.size();
    vvi table(monthNum - 1, vi(N));
    rep(i, monthNum - 1) {
        table[i] = split(stockPrices[i]);
    }
    vi finalPrices = split(stockPrices[monthNum - 1]);
    map<double, int> profitRate;
    rep(i, monthNum - 1) {
        rep(j, N) {
            if ((double) finalPrices[j] / table[i][j] > 1) {
                profitRate[(double) finalPrices[j] / table[i][j]]++;
            }
        }
    }
    int tempMoney = initialInvestment - monthlyContribution;
    double profit = 0;
    rep(i, monthNum - 1) {
        tempMoney += monthlyContribution;
        if (profitRate.empty()) break;
        while (profitRate.rbegin()->second == 0) profitRate.erase(profitRate.rbegin()->first);
        if (profitRate.empty()) break;
        double maxRate = -1; //各月で利益率が最も大きい利益率
        double rate;
        rep(j, N) {
            rate = (double) finalPrices[j] / table[i][j];
            if (rate > 1) {
                maxRate = max(maxRate, rate);
            }
            profitRate[rate]--;
        }
        if (maxRate == profitRate.rbegin()->first) { //以降の月の中で最大利益率を叩き出せる場合
            profit += tempMoney * (maxRate - 1);
            tempMoney = 0;
        }
    }
    return (int) (profit + 0.5);

}

