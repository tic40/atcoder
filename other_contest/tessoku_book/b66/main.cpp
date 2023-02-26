#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> a(m),b(m);
  REP(i,m) {
    cin >> a[i] >> b[i];
    a[i]--; b[i]--;
  }
  int q; cin >> q;
  vector<int> t(q),x(q),u(q),v(q);

  vector<bool> dis(m);
  REP(i,q) {
    cin >> t[i];
    if (t[i] == 1) { cin >> x[i]; x[i]--; dis[x[i]] = true; }
    else { cin >> u[i] >> v[i]; u[i]--; v[i]--; }
  }

  dsu uf(n);
  REP(i,m) if (!dis[i]) uf.merge(a[i],b[i]);

  vector<bool> ans;
  for(int i = q-1; i >= 0; i--) {
    if (t[i] == 1) uf.merge(a[x[i]],b[x[i]]);
    else ans.push_back(uf.same(u[i],v[i]));
  }

  reverse(ans.begin(),ans.end());
  for(bool v: ans) cout << (v ? "Yes" : "No") << endl;
  return 0;
}