#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,m;
vector<vector<int>> g,gr;
vector<bool> used;
vector<int> vs;
ll cnt = 0;

void dfs(int cur) {
  if (used[cur]) return;
  used[cur] = true;
  for (int i: g[cur]) dfs(i);
  vs.push_back(cur);

  return;
}

void dfs2(int cur) {
  if (used[cur]) return;
  used[cur]=true;
  cnt++;
  for(int i: gr[cur]) dfs2(i);

  return;
}

// 強連結成分分解
void solve() {
  vs.resize(n);
  used.resize(n);
  REP(i,n) dfs(i);

  ll ans = 0;
  reverse(vs.begin(), vs.end());
  REP(i,n) used[i] = false;

  for(int i: vs) {
    if (used[i]) continue;
    cnt = 0;
    dfs2(i);
    ans += cnt * (cnt - 1) / 2;
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n >> m;
  g.resize(n);
  gr.resize(n);

  int a,b;
  REP(i,m) {
    cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    gr[b].push_back(a);
  }

  solve();
  return 0;
}