#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 998244353;

int main() {
  ll n,m; cin >> n >> m;
  vector<ll> cnt(60); // cnt[i] := bit の i 桁目の総数 % MOD
  // i := bit の i 桁目
  REP(i,60) {
    ll mask = 1LL << i;
    if (m & mask) {
      ll period = mask << 1;
      ll full_periods = (n + 1) / period;
      cnt[i] = full_periods * mask;
      cnt[i] += max(0LL, (n + 1) % period - mask);
      cnt[i] %= MOD;
    }
  }

  ll ans = 0;
  REP(bit,60) { ans += cnt[bit]; ans %= MOD; }
  cout << ans << endl;
  return 0;
}