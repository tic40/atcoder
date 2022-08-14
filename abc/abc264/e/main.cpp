#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,m,e; cin >> n >> m >> e;
  vector<int> u(e),v(e);
  REP(i,e) { cin >> u[i] >> v[i]; u[i]--; v[i]--; }

  int q; cin >> q;
  vector<int> x(q);
  vector<bool> dis(e);
  REP(i,q) {
    cin >> x[i]; x[i]--;
    dis[x[i]] = true;
  }
  reverse(x.begin(),x.end());

  dsu d(n+m);
  // 発電所は全てつなげておく
  REP(i,m) d.merge(n,n+i);
  // q個の操作を全て終えた状態(q個切断した状態)から見ていく
  REP(i,e) if (!dis[i]) d.merge(u[i],v[i]);
  vector<int> ans(q);
  // q個切断した状態の電気が通っている都市数を求めておく
  REP(i,n) if (d.same(i,n)) ans[0]++;

  // 各操作で電気が通るようになる都市数の差分を求めていく
  for(int i = 1; i < q; i++) {
    ans[i] = ans[i-1];
    int nu = u[x[i-1]];
    int nv = v[x[i-1]];
    bool nus = d.same(nu,n);
    bool nvs = d.same(nv,n);
    if (!nus && nvs) ans[i] += d.size(nu);
    if (nus && !nvs) ans[i] += d.size(nv);
    d.merge(nu,nv);
  }

  reverse(ans.begin(),ans.end());
  for(int v: ans) cout << v << endl;
  return 0;
}