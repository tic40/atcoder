#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
using ll = long long;

ll n,x;
vector<vector<ll>> g;
ll ans = 0;

void dfs(int i, ll cur) {
  if (x < cur) return;
  if (i == n) {
    if (cur == x) ans++;
    return;
  }

  for(ll v: g[i]) {
    if (cur > x/v) continue;
    dfs(i+1, cur * v);
  }
  return;
}

int main() {
  cin >> n >> x;
  g.resize(n);
  REP(i,n) {
    ll l; cin >> l;
    REP(j,l) {
      ll a; cin >> a;
      g[i].push_back(a);
    }
  }

  dfs(0, 1);
  cout << ans << endl;
  return 0;
}