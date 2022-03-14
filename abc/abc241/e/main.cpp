#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
using ll = long long;

int n; ll k;
vector<int> a;

void solve1() {
  map<ll,pair<ll,ll>> mp; // pair<idx,x>
  ll x = 0;
  REP(i,k) {
    ll r = x%n;
    if (mp.count(r)) {
      auto [mi, mx] = mp[r];
      ll p = i - mi; // p: ループの長さ
      if ((k-i)%p == 0) { // ちょうどループで終わるところで終了する
        x += (x-mx) * ((k-i)/p);
        break;
      }
    }
    mp[r] = {i,x};
    x += a[x%n];
  }

  cout << x << endl;
}

// doubling
void solve2() {
  int logK = 1;
  while ((1LL << logK) <= k) logK++;

  vector<vector<ll>> dp(100, vector<ll>(n));
  REP(i,n) dp[0][i] = a[i];

  REP(i,logK-1) REP(j,n) {
    dp[i + 1][j] = dp[i][j] + dp[i][ (j+dp[i][j]) % n ];
  }

  ll x = 0;
  REP(i,logK) {
    if ((k >> i) & 1) x += dp[i][x%n];
  }

  cout << x << endl;
  return;
}

int main() {
  cin >> n >> k;
  a.resize(n);
  REP(i,n) cin >> a[i];

  // solve1();
  solve2();
  return 0;
}
