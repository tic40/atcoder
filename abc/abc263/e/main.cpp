#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector<vector<P>> pe(n);
  map<int,int> mx; // 素数毎に指数が最大のものを保持する
  REP(i,n) {
    int m; cin >> m;
    REP(j,m) {
      int p,e; cin >> p >> e;
      pe[i].emplace_back(p,e);
      mx[p] = max(mx[p],e);
    }
  }

  map<int,int> cnt; // 素数の指数が最大のもののカウントを取る
  REP(i,n) for(auto [p,e]: pe[i]) {
    if (mx[p] == e) cnt[p]++;
  }

  int ans = 0;
  REP(i,n) for(auto [p,e]: pe[i]) {
    // 素数毎に最大の指数の数が1個のものがあれば
    if (mx[p] == e && cnt[p] == 1) {
      ans++; break;
    }
  }

  // n未満のときは重複を取り除いた分もあるので+1する
  if (ans < n) ans++;
  cout << ans << endl;
  return 0;
}