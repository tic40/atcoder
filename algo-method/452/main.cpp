#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

// n! が素数 p で何回割れるかを求める
// ルジャンドル関数
ll legendre(ll n, ll p) {
  ll res = 0;
    while (n) {
      res += n / p;
      n /= p;
    }
    return res;
}

int main() {
  ll n; cin >> n;

  ll ans = 1;
  for (ll p = 2; p <= n; p++) {
    bool is_prime = true;
    for (ll q = 2; q*q <= p; q++) {
      if (p%q == 0) {
        is_prime = false;
        break;
      }
    }

    if (!is_prime) continue;
    ans *= legendre(n,p) + 1;
  }

  cout << ans << endl;
  return 0;
}