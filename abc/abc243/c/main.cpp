#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
const int INF = 1e9+5;

int n;
string s;
vector<int> x,y;

void solve() {
  map<int, vector<int>> mp; // <y軸の位置, 右向きの人の左橋と左向きの人の右端x位置>
  REP(i,n) mp[y[i]] = vector<int>{ INF, -INF };
  REP(i,n) {
    if (s[i] == 'R') mp[ y[i] ][0] = min(mp[ y[i] ][0], x[i]);
    if (s[i] == 'L') mp[ y[i] ][1] = max(mp[ y[i] ][1], x[i]);
  }

  bool ok = false;
  for(auto [k,v]: mp) if (v[0] < v[1]) ok = true;
  cout << (ok ? "Yes" : "No") << endl;

  return;
}

int main() {
  cin >> n;
  x.resize(n); y.resize(n);
  REP(i,n) cin >> x[i] >> y[i];
  cin >> s;

  solve();
  return 0;
}