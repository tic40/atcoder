#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m,e; cin >> n >> m >> e;
  vector<int> u(e),v(e);
  REP(i,e) {
    cin >> u[i] >> v[i];
    u[i]--; v[i]--;
  }

  int q; cin >> q;
  vector<bool> dis(e);
  vector<int> x(q);
  REP(i,q) {
    cin >> x[i]; x[i]--;
    dis[x[i]] = true;
  }
  reverse(x.begin(),x.end());

  vector<vector<int>> g(n+m);
  dsu d(n+m);
  // 発電所は全部つなげる
  for(int i = 1; i < m; i++) d.merge(n,i+n);

  // q個の操作しきった状態から見ていく
  REP(i,e) {
    if (dis[i]) continue;
    d.merge(u[i],v[i]);
  }

  vector<int> ans(q);
  // q個の操作を全て終えたときの電気が通っている都市数
  REP(i,n) if (d.same(i,n)) ans[0]++;

  for(int i = 1; i < q; i++) {
    // q個の操作を逆から見ていき、電線をつなげたときに新たに通る都市数の差分を求める
    ans[i] = ans[i-1];
    int nu = u[x[i-1]];
    int nv = v[x[i-1]];
    bool nud = d.same(nu,n);
    bool nvd = d.same(nv,n);
    if (nud && !nvd) ans[i] += d.size(nv);
    if (!nud && nvd) ans[i] += d.size(nu);
    d.merge(nu,nv);
  }

  reverse(ans.begin(),ans.end());
  REP(i,q) cout << ans[i] << endl;
  return 0;
}