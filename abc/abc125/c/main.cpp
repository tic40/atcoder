#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {
  if (a == 0 || b == 0) return a + b;
  return (a >= b) ? gcd(b, a % b) : gcd(a, b % a);
}

int main() {
  int n, ans = 0;
  cin >> n;
  vector<int> a(n), l(n + 1, 0), r(n + 2, 0);
  for (int i = 0; i < n; i++) cin >> a[i];
  for (int i = 0; i < n; i++) {
    l[i + 1] = gcd(l[i], a[i]);
    r[n - i] = gcd(r[n - i + 1], a[n - i - 1]);
  }
  for (int i = 0; i <= n; i++) ans = max(ans, gcd(l[i], r[i + 2]));
  cout << ans << "\n";
}