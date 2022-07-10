#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

ll dist(ll a, ll b) { return a*a+b*b; }
ll pow(ll a) { return a*a; }

int main() {
  int n; cin >> n;
  ll sx,sy,tx,ty;
  cin >> sx >> sy >> tx >> ty;

  vector<ll> x(n),y(n),r(n);
  REP(i,n) cin >> x[i] >> y[i] >> r[i];

  int si = -1, ti = - 1;
  REP(i,n) {
    if (dist(x[i]-sx,y[i]-sy) == pow(r[i])) si = i;
    if (dist(x[i]-tx,y[i]-ty) == pow(r[i])) ti = i;
  }

  dsu uf(n);
  REP(i,n) for(int j = i+1; j < n; j++) {
    ll nd = dist(x[i]-x[j],y[i]-y[j]);
    if (nd > pow(r[i]+r[j])) continue; // nd < ri+rj のとき離れすぎている
    // ri >= rj とすると、 nd + rj < ri のときiの円の中にjの円が円周に接しない形で内包している
    if (nd < pow(r[i]-r[j])) continue;

    uf.merge(i,j);
  }

  cout << (uf.same(si,ti) ? "Yes" : "No") << endl;
  return 0;
}