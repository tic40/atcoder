#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

vector<bool> eratosthenes(int n) {
  vector<bool> primes(n+1, true);

  primes[0] = false;
  primes[1] = false;
  for (int i = 2; i <= n; i++) {
    if (!primes[i]) continue;
    for (int j = 2*i; j <= n; j+=i) primes[j] = false;
  }
  return primes;
}

int main() {
  int n; cin >> n;
  auto primes = eratosthenes(n);
  int ans = 0;
  REP(i,n-1) {
    if (primes[i] && primes[i+2]) ans++;
  }
  cout << ans << endl;
  return 0;
}