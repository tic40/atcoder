#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int n;
vector<vector<pair<int, int>>> g;
vector<bool> checked;
vector<int> ans;

void dfs(int cur, int pcol) {
  if (checked[cur]) return;

  int k = 1;
  checked[cur]=true;
  for (auto v: g[cur]) {
    int to = v.first, idx = v.second;
    if (checked[to]) continue;
    if (k == pcol) k++;
    ans[idx] = k;
    dfs(to, k);
    k++;
  }
  return;
}

void solve() {
  ans.resize(n-1);
  checked.resize(n);
  REP(i,n) dfs(i,0);

  cout << *max_element(ans.begin(), ans.end()) << endl;
  for(int v: ans) cout << v << endl;
  return;
}

int main() {
  cin >> n;
  g.resize(n);
  REP(i,n-1) {
    int a,b;
    cin >> a >> b;
    a--; b--;
    g[a].push_back({b,i});
    g[b].push_back({a,i});
  }

  solve();
  return 0;
}