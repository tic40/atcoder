#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> v(n), c(n);
  for (int i = 0; i < n; i++) cin >> v[i];
  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) if (v[i] - c[i] > 0) ans += v[i] - c[i];
  cout << ans << "\n";
}