#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n,q;
vector<ll> a,b;

void solve() {
  sort(a.begin(), a.end());

  REP(i,q) {
    auto it = lower_bound(a.begin(), a.end(), b[i]);
    int idx = it-a.begin();
    ll ans = min( abs(b[i]-a[idx]), abs(b[i]-a[max(0, idx-1)]) );
    cout << ans << endl;
  }

  return;
}

int main() {
  cin >> n;
  a.resize(n);
  REP(i,n) cin >> a[i];
  cin >> q;
  b.resize(q);
  REP(i,q) cin >> b[i];

  solve();
  return 0;
}