#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n,q;
vector<int> a,b,p,x;
vector<vector<int>> g;
vector<int> s;

void dfs(int now, int from = -1) {
  for(int ni: g[now]) {
    if (ni == from) continue;
    s[ni]+=s[now];
    dfs(ni, now);
  }
  return;
}

void solve() {
  g.resize(n);
  REP(i,n-1) {
    g[a[i]].push_back(b[i]);
    g[b[i]].push_back(a[i]);
  }

  // 累積和
  s.resize(n);
  REP(i,q) s[p[i]] += x[i];

  dfs(0);
  REP(i,n) cout << s[i] << " ";
  return;
}

int main() {
  cin >> n >> q;
  a.resize(n-1),b.resize(n-1);
  p.resize(q); x.resize(q);
  REP(i,n-1) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  REP(i,q) {
    cin >> p[i] >> x[i];
    p[i]--;
  }

  solve();
  return 0;
}