#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353; // modint1000000007;

int main() {
  int n,m; cin >> n >> m;
  vector<ll> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];
  sort(b.begin(),b.end());
  vector<ll> s(m+1);
  REP(i,m) s[i+1] = s[i]+b[i];

  mint ans = 0;
  REP(i,n) {
    auto it = lower_bound(b.begin(),b.end(),a[i]);
    int idx = it - b.begin();
    ll tot = 0;
    tot += a[i] * idx - s[idx];
    tot += s[m] - s[idx] - (a[i] * (m - idx));
    ans += tot;
  }

  cout << ans.val() << endl;
  return 0;
}
