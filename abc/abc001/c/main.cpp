#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int deg,dis; cin >> deg >> dis;
  const vector<string> directions = {
    "NNE","NE","ENE","E","ESE","SE","SSE",
    "S","SSW","SW","WSW","W","WNW","NW","NNW"
  };

  string C = "C";
  string dir = "N";
  REP(i,15) {
    int l = 112 + (225 * i);
    int r = 337 + (225 * i);
    if (l < deg && deg <= r) dir = directions[i];
  }

  int w = 0;
  double p = round((double)dis / 6.0) / 10.0;
  if (0.0 <= p && p <= 0.2) { w = 0; dir = C; }
  if (0.3 <= p && p <= 1.5) w = 1;
  if (1.6 <= p && p <= 3.3) w = 2;
  if (3.4 <= p && p <= 5.4) w = 3;
  if (5.5 <= p && p <= 7.9) w = 4;
  if (8.0 <= p && p <= 10.7) w = 5;
  if (10.8 <= p && p <= 13.8) w = 6;
  if (13.9 <= p && p <= 17.1) w = 7;
  if (17.2 <= p && p <= 20.7) w = 8;
  if (20.8 <= p && p <= 24.4) w = 9;
  if (24.5 <= p && p <= 28.4) w = 10;
  if (28.5 <= p && p <= 32.6) w = 11;
  if (32.7 <= p) w = 12;

  cout << dir << " " << w << endl;
  return 0;
}