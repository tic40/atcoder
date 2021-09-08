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
  vector<bool> n(100, 1);
  int ans = 0;
  REP(i,100) {
    if (i <= 2) continue;
    if (i % 2 == 0 || i % 3 == 0 || i % 5 == 0) continue;
    if (ok(i)) ans++;
  }

  cout << ans << endl;
  return 0;
}