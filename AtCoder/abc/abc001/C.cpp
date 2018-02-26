// finish date: 2018/01/03
#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

#define FOR(i, a, b) for(int i=a;i<b;i++)
#define rep(i, n)  FOR(i,0,n)

int main() {
    double Deg, Dis;
    string Dir = "N";
    int W = 0;
    cin >> Deg >> Dis;
    Deg /= 10;
    if (11.25 <= Deg && Deg < 33.75) Dir = "NNE";
    else if (33.75 <= Deg && Deg < 56.25) Dir = "NE";
    else if (56.25 <= Deg && Deg < 78.75) Dir = "ENE";
    else if (78.75 <= Deg && Deg < 101.25) Dir = "E";
    else if (101.25 <= Deg && Deg < 123.75) Dir = "ESE";
    else if (123.75 <= Deg && Deg < 146.25) Dir = "SE";
    else if (146.25 <= Deg && Deg < 168.75) Dir = "SSE";
    else if (168.75 <= Deg && Deg < 191.25) Dir = "S";
    else if (191.25 <= Deg && Deg < 213.75) Dir = "SSW";
    else if (213.75 <= Deg && Deg < 236.25) Dir = "SW";
    else if (236.25 <= Deg && Deg < 258.75) Dir = "WSW";
    else if (258.75 <= Deg && Deg < 281.25) Dir = "W";
    else if (281.25 <= Deg && Deg < 303.75) Dir = "WNW";
    else if (303.75 <= Deg && Deg < 326.25) Dir = "NW";
    else if (326.25 <= Deg && Deg < 348.75) Dir = "NNW";

    Dis = round(Dis / 60 * 10) / 10;
    if (0.0 <= Dis && Dis <= 0.2) {
        W = 0;
        Dir = "C";
    } else if (0.3 <= Dis && Dis <= 1.5) W = 1;
    else if (1.6 <= Dis && Dis <= 3.3) W = 2;
    else if (3.4 <= Dis && Dis <= 5.4) W = 3;
    else if (5.5 <= Dis && Dis <= 7.9) W = 4;
    else if (8.0 <= Dis && Dis <= 10.7) W = 5;
    else if (10.8 <= Dis && Dis <= 13.8) W = 6;
    else if (13.9 <= Dis && Dis <= 17.1) W = 7;
    else if (17.2 <= Dis && Dis <= 20.7) W = 8;
    else if (20.8 <= Dis && Dis <= 24.4) W = 9;
    else if (24.5 <= Dis && Dis <= 28.4) W = 10;
    else if (28.5 <= Dis && Dis <= 32.6) W = 11;
    else if (32.7 <= Dis) W = 12;
    cout << Dir << " " << W << endl;
    return 0;
}
