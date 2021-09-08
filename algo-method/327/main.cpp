#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

bool ok(int n) {
  for(int i = 2; i*i <= n; i++) {
    if (n % i == 0) return true;
  }
  return false;
}

int main() {
  vector<bool> n(31, 1);
  REP(i,31) {
    if (i <= 2) continue;
    if (i % 2 == 0 || i % 3 == 0) continue;
    if (ok(i)) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}