#include <bits/stdc++.h>
using namespace std;

int main() {
  int i, j, n;
  double ans = 0;
  cin >> n;
  vector<int> c(n);

  for (int i = 0; i < n; i++) cin >> c[i];
  for (int i = 0; i < n; i++) {
    int s = 0;
    for (int j = 0; j < n; j++) if (i != j && c[i] % c[j] == 0) s++;
    ans += (s % 2 == 0) ? 1.0 * (s + 2) / (2 * s + 2) : 0.5;
    cout << ans;
  }
  cout << fixed << setprecision(10) << ans << "\n";
}