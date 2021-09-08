#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

bool is_prime(int n) {
  if (n == 1) return false;
  for(int i = 2; i*i <= n; i++) {
    if (n % i == 0) return false;
  }
  return true;
}

int main() {
  int n; cin >> n;
  cout << (is_prime(n) ? "Yes" : "No") << endl;
  return 0;
}