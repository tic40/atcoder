#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int x,y,a,b,c;
vector<int> p,q,r;

void solve() {
  sort(p.rbegin(), p.rend());
  sort(q.rbegin(), q.rend());
  sort(r.rbegin(), r.rend());
  vector<int> res;

  REP(i,x) res.push_back(p[i]);
  REP(i,y) res.push_back(q[i]);
  sort(res.begin(), res.end());

  int cur = 0;
  REP(i,x+y) {
    if (r[cur] <= res[i]) break;
    res[i] = r[cur];
    cur++;
  }

  ll ans = 0;
  REP(i,x+y) ans += res[i];
  cout << ans << endl;
  return;
}

int main() {
  cin >> x >> y >> a >> b >> c;
  p.resize(a);
  q.resize(b);
  r.resize(c);
  REP(i,a) cin >> p[i];
  REP(i,b) cin >> q[i];
  REP(i,c) cin >> r[i];

  solve();
  return 0;
}