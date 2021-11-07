#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

int n;
vector<ll> t;
vector<vector<int>> g;
vector<bool> ok;

ll dfs(int cur) {
  ll res = 0;
  if (ok[cur]) return res;

  for(int v: g[cur]) {
    if (ok[v]) continue; // 習得済み
    res += dfs(v);
  }
  res += t[cur];
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

  ll ans = dfs(n-1);
  cout << ans << endl;

  return 0;
}