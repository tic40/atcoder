#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
const int INF = numeric_limits<int>::max();

// リールを止める順番
const vector<vector<int>> orders = {
  { 0,1,2 },{ 0,2,1 },
  { 1,0,2 },{ 1,2,0 },
  { 2,0,1 },{ 2,1,0 }
};

int main() {
  int m; cin >> m;
  vector<string> s(3);
  REP(i,3) cin >> s[i];
  // g[i][j] := i 番目のリールでスロットの表示に j が現れる時間の集合
  vector g(3,vector(10,vector<int>()));
  REP(i,3) REP(j,m) g[i][s[i][j]-'0'].push_back(j);

  auto impossible = [&](int i) {
    REP(j,3) if (g[j][i].size() == 0) return true;
    return false;
  };

  int ans = INF;
  REP(i,10) {
    if (impossible(i)) continue; // i|i|i でリールを止められるか
    for(auto order: orders) {
      int t = 0;
      for(int reel: order) {
        int modt = t%m;
        auto it = lower_bound(g[reel][i].begin(),g[reel][i].end(),modt);
        if (it == g[reel][i].end()) t += m - modt + g[reel][i][0];
        else t += *it - modt;
        t += 1;
      }
      ans = min(ans,t-1);
    }
  }

  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}