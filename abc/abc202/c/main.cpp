#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a,b,c;

void solve() {
  vector<int> d(n);
  REP(i,n) d[i] = b[c[i]];

  map<int, ll> ma, md;
  REP(i,n) {
    ma[a[i]]++;
    md[d[i]]++;
  }

  ll ans = 0;
  for(auto v: ma) {
    if (md[v.first]) ans += v.second * md[v.first];
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n); b.resize(n); c.resize(n);

  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];
  REP(i,n) { cin >> c[i]; c[i]--; }

  solve();
  return 0;
}