#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

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
  int q; cin >> q;
  auto p = eratosthenes(3e5+1);
  REP(i,q) {
    int x; cin >> x;
    cout << (p[x] ? "Yes" : "No") << endl;
  }
  return 0;
}