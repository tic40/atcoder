#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

int n;
vector<ll> t;
vector<vector<int>> g;
vector<bool> ok;

ll dfs(int cur) {
  if (ok[cur]) return 0;

  ll res = t[cur];
  for(int v: g[cur]) {
    if (ok[v]) continue;
    res += dfs(v);
  }
  ok[cur] = true;
  return res;
}

int main() {
  cin >> n;
  t.resize(n);
  g.resize(n);
  ok.resize(n);

  REP(i,n) {
    cin >> t[i];
    int k; cin >> k;
    REP(j,k) {
      int a;
      cin >> a; a--;
      g[i].push_back(a);
    }
  }

  cout << dfs(n-1) << endl;
  return 0;
}