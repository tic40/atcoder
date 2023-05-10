#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

struct Sieve {
  int n; vector<int> f,primes;
  Sieve(int n=1): n(n), f(n+1) {
    f[0] = f[1] = -1;
    for (ll i = 2; i <= n; i++) {
      if (f[i]) continue;
      primes.push_back(i);
      f[i] = i;
      for(ll j = i*i; j <= n; j += i) if (!f[j]) f[j] = i;
    }
  }
};

int main() {
  ll n; cin >> n;
  Sieve sieve(sqrt(n));
  auto p = sieve.primes;
  int sz = p.size();

  int ans = 0;
  REP(i,sz) for(int j = i+1; j < sz; j++) {
    ll a = p[i], b = p[j];
    ll c = sqrt( n / (a*a*b) );
    if (c <= b) break;
    int idx = upper_bound(p.begin(),p.end(),c) - p.begin();
    ans += max(0, idx-j-1);
  }

  cout << ans << endl;
  return 0;
}