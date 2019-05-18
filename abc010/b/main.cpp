#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

bool like(int leafs) {
  return leafs % 2 == 1 && leafs % 3 != 2;
}

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  REP(i, n) {
    if (like(a[i])) continue;
    REPR(j, a[i] - 1) {
      if (like(j)) {
        ans += a[i] - j;
        break;
      }
    }
  }
  cout << ans << "\n";
}
