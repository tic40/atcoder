#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  scc_graph g(n);
  int ans = 0;
  REP(i,n) {
    g.add_edge(i,a[i]);
    if (i == a[i]) ans++;
  }

  for(auto c: g.scc()) {
    if (c.size() >= 2) ans += c.size();
  }
  cout << ans << endl;
  return 0;
}