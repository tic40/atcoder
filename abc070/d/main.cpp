#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;
using P = pair<int, int>;

int n,q,k;
vector<vector<P>> g;
vector<ll> x,y,d;

void dfs(int cur) {
  for(auto v: g[cur]) {
    int to = v.first;
    int c = v.second;
    ll nd = d[cur]+c;
    if (nd < d[to]) {
      d[to] = nd;
      dfs(to);
    }
  }
  return;
}

void solve() {
  d.resize(n, LINF);
  d[k] = 0;
  dfs(k);
  REP(i,q) cout << d[x[i]] + d[y[i]] << endl;

  return;
}

int main() {
  cin >> n;
  g.resize(n);
  int a,b,c;
  REP(i,n-1) {
    cin >> a >> b >> c;
    a--; b--;
    g[a].emplace_back(P({b, c}));
    g[b].emplace_back(P({a, c}));
  }

  cin >> q >> k;
  k--;
  x.resize(q);
  y.resize(q);
  REP(i,q) {
    cin >> x[i] >> y[i];
    x[i]--; y[i]--;
  }

  solve();
  return 0;
}