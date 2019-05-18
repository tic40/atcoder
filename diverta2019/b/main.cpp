#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int r,g,b,n, ans = 0;
  cin >> r >> g >> b >> n;

  REP (i, (n / r) + 1) {
    REP (j, (n / g) + 1) {
      int sum = i * r + j * g;
      if (n < sum) break;
      if (n == sum) ans++;
      else if (n - sum < b ^ 2 && (n - sum) % b == 0) ans++;
    }
  }
  cout << ans << "\n";
}