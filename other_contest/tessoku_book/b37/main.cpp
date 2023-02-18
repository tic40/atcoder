#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;

  vector<ll> p10(18);
  p10[0] = 1;
  for(int i = 1; i <= 16; i++) p10[i] = 10LL * p10[i-1];

  vector r(18,vector<ll>(10));
  REP(i,16) {
    // 下から i 桁目の数字を求める
    ll d = (n / p10[i]) % 10LL;
    REP(j,10) {
      if (j < d) {
        r[i][j] = (n/p10[i+1] + 1LL) * p10[i];
      } else if (j == d) {
        r[i][j] = (n/p10[i+1]) * p10[i] + (n%p10[i]) + 1LL;
      } else {
        r[i][j] = (n/p10[i+1]) * p10[i];
      }
    }
  }

  ll ans = 0;
  REP(i,16) REP(j,10) ans += 1LL * j * r[i][j];
  cout << ans << endl;
  return 0;
}