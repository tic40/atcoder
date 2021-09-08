#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

bool is_prime(ll n) {
  if (n == 1) return false;
  for (ll i = 2; i*i <= n; ++i) {
    if (n % i == 0) return false;
  }
  return true;
}


int main() {
  int n;
  cin >> n;
  while(1) {
    if (is_prime(n)) {
      cout << n << endl;
      return 0;
    }
    n--;
  }

  return 0;
}