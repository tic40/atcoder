#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> b(n),w(m);
  REP(i,n) cin >> b[i];
  REP(i,m) cin >> w[i];
  sort(b.rbegin(),b.rend());
  sort(w.rbegin(),w.rend());

  ll ans = 0, sb = 0, sw = 0;
  REP(i,n) {
    sb += b[i];
    if (i < m && w[i] > 0) sw += w[i];
    ans = max(ans,sb+sw);
  }
  cout << ans << endl;
  return 0;
}
