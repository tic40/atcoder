#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  ll n; cin >> n;

  int n2 = sqrt(n);
  vector<int> is_prime(n2+1,1);
  vector<int> primes;
  for(int i = 2; i <= n2; i++) {
    if (!is_prime[i]) continue;
    primes.push_back(i);
    for(int j = i*2; j <= n2; j+=i) is_prime[j] = 0;
  }

  int sz = primes.size();
  int ans = 0;
  for(auto v: primes) {
    ll now = v;
    int cnt = 1;
    while(cnt < 8 && now*v <= n) { now *= v; cnt++; }
    if (cnt < 8) break;
    ans++;
  }

  REP(i,sz) {
    ll a = (ll)primes[i] * primes[i];
    for(int j = i+1; j < sz; j++) {
      ll b = (ll)primes[j] * primes[j];
      if (a > n/b) break;
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}