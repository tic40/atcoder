#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const ll LINF = 1e18;

vector<bool> eratosthenes(ll n) {
  vector<bool> primes(n+1, true);

  primes[0] = false;
  primes[1] = false;
  for (ll i = 2; i <= n; i++) {
    if (!primes[i]) continue;
    for (ll j = 2*i; j <= n; j+=i) primes[j] = false;
  }
  return primes;
}

int main() {
  ll a,b;
  cin >> a >> b;

  // √b以下の素数を列挙する
  auto p = eratosthenes(floor(sqrt(b)));
  vector<bool> ans(b-a+1, 1);

  REP(i, p.size()) {
    if (!p[i]) continue;
    // A 以上の最小の i の倍数
    ll start = (a+i-1) / i*i;
    // コーナーケース
    // A 以上 B 以下の i の倍数をふるい落とすときに、i もふるい落としてしまうとだめ
    if (start == i) start = i * 2;
    for (ll j=start; j <= b; j+=i) ans[j-a] = 0;
  }

  int cnt = 0;
  for(int v: ans) if (v) cnt++;
  cout << cnt << endl;
  return 0;
}