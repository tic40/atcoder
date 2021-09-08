#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

vector<int> eratosthenes(int n) {
  vector<int> primes(n+1);
  for(int i=2; i<=n; i++) {
    if(0 <= primes[i]) {
      for(int j=2*i; j<=n; j+=i) primes[j] = -1;
      primes[i] = 1;
    }
  }
  return primes;
}

int main() {
  int n; cin >> n;
  auto v = eratosthenes(n);
  int ans = -1;
  REP(i,n+1) {
    if (v[i] == 1 && v[n-i] == 1) {
      ans = i;
      break;
    }
  }

  cout << ans << endl;
  return 0;
}