#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> a,b;

void solve() {
  vector<pair<ll, int>> s(n);
  REP(i,n) s[i] = { a[i]+b[i], i };
  sort(s.rbegin(),s.rend());

  ll ans = 0;
  REP(i,n) {
    if (i%2==0) ans += a[s[i].second];
    else ans -= b[s[i].second];
  }

  cout << ans << endl;
  return;
}

int main() {
  cin >> n;
  a.resize(n); b.resize(n);
  REP(i,n) cin >> a[i] >> b[i];

  solve();
  return 0;
}