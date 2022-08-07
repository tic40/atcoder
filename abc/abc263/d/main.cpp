#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,l,r; cin >> n >> l >> r;
  vector<int> a(n);
  REP(i,n) cin >> a[i];

  // dp[j]
  // j = 0: i <= x;
  // j = 1: x < y < y
  // j = 2: y <= i
  vector<ll> dp = { l, a[0], r };
  for(int i = 1; i < n; i++) {
    vector<ll> p(3);
    swap(dp,p);
    dp[0] += p[0] + l;
    dp[1] += min(p[0],p[1]) + a[i];
    dp[2] += min(p[1],p[2]) + r;
  }

  ll ans = min({dp[0],dp[1],dp[2]});
  cout << ans << endl;
  return 0;
}