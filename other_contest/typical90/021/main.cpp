#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,m;
vector<vector<int>> g(1e5),gr(1e5);
vector<int> dir;
vector<bool> used;
ll cnt = 0;

void dfs1(int cur) {
  if (used[cur]) return;
  used[cur]=true;
  for (int v: g[cur]) dfs1(v);
  dir.push_back(cur);

  return;
}

void dfs2(int cur) {
  if (used[cur]) return;
  used[cur]=true;
  cnt++;
  for (int v: gr[cur]) dfs2(v);

  return;
}

// 強連結成分分解
void solve1() {
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  used.resize(n, false);
  REP(i,n) dfs1(i);

  ll ans = 0;
  reverse(dir.begin(), dir.end());
  REP(i,n) used[i] = false;

  for(int i: dir) {
    cnt = 0;
    dfs2(i);
    ans += cnt * (cnt-1) / 2;
  }
  cout << ans << endl;
  return;
}

// ac libraryを使う場合
void solve2() {
  scc_graph sg(n);
  REP(i,m) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    sg.add_edge(a,b);
  }
  auto scc = sg.scc();
  ll ans = 0;
  for(auto v: scc) ans += v.size() * (v.size()-1) / 2;
  cout << ans << endl;
}

int main() {
  cin >> n >> m;
  // solve1();
  solve2();
  return 0;
}