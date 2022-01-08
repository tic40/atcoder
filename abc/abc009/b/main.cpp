#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n;
  cin >> n;
  vector<int> a(n);
  REP(i, n) cin >> a[i];
  sort(a.begin(), a.end(), greater<int>());
  int ans = a[0];
  FOR(i, 1, n) {
    if (ans != a[i]) {
      ans = a[i];
      break;
    }
  }
  cout << ans << "\n";
}