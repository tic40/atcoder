#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int n;
vector<int> x,y;

void solve() {
  if (n <= 2) { cout << 1 << endl; return; }

  vector<pair<int,int>> pa;
  REP(i,n) REP(j,n) {
    if (i == j) continue;
    pa.push_back({x[i]-x[j], y[i]-y[j]});
  }

  int ans = INF;
  for(auto v: pa) {
    int p = v.first, q = v.second, cost = 0;
    REP(j,n) {
      int a = x[j], b = y[j], ok = false;
      REP(k,n) {
        if (a+p == x[k] && b+q == y[k]) ok = true;
      }
      if (!ok) cost++;
    }
    ans = min(ans,cost);
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  x.resize(n); y.resize(n);
  REP(i,n) cin >> x[i] >> y[i];

  solve();
  return 0;
}