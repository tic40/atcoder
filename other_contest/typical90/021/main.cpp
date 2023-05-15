#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

void solve1() {
  int n,m; cin >> n >> m;
  vector<vector<int>> g(n),gr(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  vector<int> dir;
  vector<bool> used(n);
  auto dfs1 = [&](auto self, int i) {
    if (used[i]) return;
    used[i] = true;
    for(auto v: g[i]) self(self,v);
    dir.push_back(i);
  };
  auto dfs2 = [&](auto self, int i) {
    if (used[i]) return 0;
    used[i] = true;
    int res = 1;
    for(auto v: gr[i]) res += self(self,v);
    return res;
  };

  REP(i,n) dfs1(dfs1,i);
  reverse(dir.begin(), dir.end());
  used = vector<bool>(n);
  ll ans = 0;
  for(int i: dir) {
    int cnt = dfs2(dfs2,i);
    ans += (ll)cnt * (cnt-1) / 2;
  }
  cout << ans << endl;
  return;
}

// ac libraryを使う場合
void solve2() {
  int n,m; cin >> n >> m;
  scc_graph sg(n);
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    sg.add_edge(a,b);
  }
  auto scc = sg.scc();
  ll ans = 0;
  for(auto v: scc) ans += v.size() * (v.size()-1) / 2;
  cout << ans << endl;
}

int main() {
  solve1();
  // solve2();
  return 0;
}