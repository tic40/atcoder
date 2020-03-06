#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  int s[m],c[m];
  REP(i,m) cin >> s[i] >> c[i];

  int a[n];
  for (int i = (n == 1 ? 0 : pow(10, n-1)); i < pow(10, n); i++) {
    int ok = 1;
    int tmp = i;
    REP(i, n) {
      a[i] = tmp % 10;
      tmp /= 10;
    }
    REP(j,m) {
      if (a[n - s[j]] != c[j] ) { ok = 0; break; }
    }
    if (ok) {
      cout << i << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}