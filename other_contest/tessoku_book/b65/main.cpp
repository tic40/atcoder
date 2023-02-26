#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

vector g(1e5, vector<int>());
vector<int> ans(1e5);

int dfs(int i, int p) {
  int now = 0;
  for(int v: g[i]) {
    if (v == p) continue;
    now = max(now,dfs(v,i));
  }
  ans[i] = now;
  return now+1;
}

int main() {
  int n,t; cin >> n >> t;
  t--;
  REP(i,n-1) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  dfs(t,-1);
  REP(i,n) cout << ans[i] << " ";
  return 0;
}