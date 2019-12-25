#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, x, ans = 0;
  cin >> n >> x;
  int a[n];
  REP(i, n) cin >> a[i];

  for (int i = 0; i < n; i++) {
    if (x & (1 << (i))) ans += a[i];
  }
  cout << ans << endl;
}