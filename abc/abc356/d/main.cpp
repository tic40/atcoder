#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int MOD = 998244353;

int main() {
  ll n,m; cin >> n >> m;
  vector<ll> bit_counts(60);
  REP(bit,60) {
    ll mask = 1LL << bit;
    if (m & mask) {
      ll period = mask << 1;
      ll full_periods = (n + 1) / period;
      bit_counts[bit] = full_periods * mask + max(0LL, (n + 1) % period - mask);
    }
  }

  ll ans = 0;
  REP(bit,60) ans = (ans + bit_counts[bit]) % MOD;
  cout << ans << endl;
  return 0;
}