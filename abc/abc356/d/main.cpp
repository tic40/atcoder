#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using mint = modint998244353;

int main() {
  ll n,m; cin >> n >> m;

  auto solve1 = [&]() {
    mint ans = 0;
    REP(i,60) {
      ll mask = 1LL << i;
      if (m & mask) {
        ll period = mask << 1;
        ans += (n+1) / period * mask;
        ans += max(0LL, (n+1) % period - mask);
      }
    }
    cout << ans.val() << endl;
  };

  // bit 各桁の周期から数え上げる解法
  auto solve2 = [&]() {
    mint ans = 0;
    REP(i,60) if (m >> i & 1) {
      ll p = 1LL << (i+1);
      ll r = n % p;
      ans += (n-r) / 2; // 周期分
      ans += max(0LL, r - (1LL << i) + 1);
    }
    cout << ans.val() << endl;
  };

  // solve1();
  solve2();
  return 0;
}