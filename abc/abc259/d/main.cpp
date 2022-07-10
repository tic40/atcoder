#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n,sx,sy,tx,ty;
  cin >> n >> sx >> sy >> tx >> ty;
  vector<ll> x(n),y(n),r(n);
  REP(i,n) cin >> x[i] >> y[i] >> r[i];

  // sqrtすると誤差が発生するため、2乗した整数のまま扱う
  auto dist = [](ll a, ll b) { return a*a + b*b; };
  auto pow = [](ll a) { return a*a; };

  dsu uf(n);
  REP(i,n) for(int j = i+1; j < n; j++) {
    // iとjの距離
    ll nd = dist(x[i]-x[j], y[i]-y[j]);
    if (nd < pow(r[j]-r[i]) ) continue;
    if (pow(r[i]+r[j]) < nd) continue;
    uf.merge(i,j);
  }

  // sx,syとtx,tyはどの円周上にあるかを見つける
  int si, ti;
  REP(i,n) {
    if (dist(x[i] - sx, y[i] - sy) == pow(r[i])) si = i;
    if (dist(x[i] - tx, y[i] - ty) == pow(r[i])) ti = i;
  }

  cout << (uf.same(si,ti) ? "Yes" : "No") << endl;
  return 0;
}