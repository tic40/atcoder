#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll LINF = 1e18;

int n,m;
vector<ll> a,b;

void solve() {
  sort(a.begin(), a.end());
  sort(b.begin(), b.end());

  ll ans = LINF;
  int ai = 0, bi = 0;
  while (ai < n && bi < m) {
    ans = min(ans, abs(a[ai] - b[bi]));
    if (a[ai] < b[bi]) ai++;
    else bi++;
  }

  cout << ans << endl;;
  return;
}

int main() {
  cin >> n >> m;
  a.resize(n);
  b.resize(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  solve();
  return 0;
}