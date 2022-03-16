#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int n; ll k;
vector<int> a;

ll solve1() {
  map<int,pair<int,ll>> mp;
  ll x = 0;
  REP(i,k) {
    ll r = x % n;
    if (mp.count(r)) {
      auto [mi,mx] = mp[r];
      int p = i - mi;
      if ( (k - i) % p == 0) { // ループが割り切れるところで打ち切ると計算が楽
        x += (x-mx) * ((k-i)/p);
        break;
      }
    }

    mp[r] = {i,x};
    x += a[r];
  }

  return x;
}

// ダブリング解
ll solve2() {
  int logK = 1;
  while ((1LL << logK) <= k) logK++;
  vector<vector<ll>> dp(logK, vector<ll>(n));
  REP(i,n) dp[0][i] = a[i];

  REP(i,logK-1) REP(j,n) {
    dp[i+1][j] = dp[i][j] + dp[i][ (j + dp[i][j])%n ];
  }

  ll x = 0;
  REP(i,logK) {
    if (k >> i & 1) x += dp[i][x % n];
  }
  return x;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  cout << solve1() << endl;
  cout << solve2() << endl;
  return 0;
}
