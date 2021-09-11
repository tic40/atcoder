#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)

int main() {
  int n = 56;
  int ans = 0;
  for (int i = 1; i <= n; i++) {
    if (n % i == 0) ans++;
  }
  cout << ans << endl;
  return 0;
}