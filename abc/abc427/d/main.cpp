#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

void solve() {
  int n,m,k; cin >> n >> m >> k;
  string s; cin >> s;
  vector g(n,vector<int>());
  REP(i,m) {
    int u,v; cin >> u >> v; u--; v--;
    g[u].push_back(v);
  }

  map<P,bool> memo;
  // player = cnt%2 が勝つかどうかを判定
  auto dfs = [&](auto& dfs, int i, int cnt) -> bool {
    P key = {i,cnt};
    if (memo.count(key)) return memo[key];

    int player = cnt%2;
    if (cnt == k*2) return (s[i] == 'A' ? 0 : 1) == player;

    bool res = false;
    for(auto v: g[i]) res = res || !dfs(dfs,v,cnt+1);
    return memo[key] = res;
  };

  cout << (dfs(dfs,0,0) ? "Alice" : "Bob") << endl;
}

int main() {
  int t; cin >> t;
  REP(_,t) solve();
  return 0;
}