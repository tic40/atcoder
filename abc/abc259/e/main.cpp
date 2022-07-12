#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<vector<P>> pe(n);
  REP(i,n) {
    int m; cin >> m;
    REP(j,m) {
      int p,e; cin >> p >> e;
      pe[i].emplace_back(p,e);
    }
  }

  // maxを探す
  map<int,int> mx; // [素数, 指数]
  REP(i,n) for(auto [p,e]: pe[i]) {
    mx[p] = max(mx[p], e);
  }

  // 単独maxを見つけるためにカウントする
  map<int,int> cnt;
  REP(i,n) for(auto [p,e]: pe[i]) {
    if (mx[p] == e) cnt[p]++;
  }

  int ans = 0;
  REP(i,n) for(auto [p,e]: pe[i]) {
    // 単独maxが存在する場合
    if (mx[p] == e && cnt[p] == 1) {
      ans++; break;
    }
  }

  // 消しても変わらないケースを+1する
  // ただし、どれを消しても変わる場合は+1しない
  if (ans < n) ans++;
  cout << ans << endl;

  return 0;
}