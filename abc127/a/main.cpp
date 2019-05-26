#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int a, b, ans = 0;
  cin >> a >> b;
  if (6 <= a && a <= 12) ans = b / 2;
  else if (13 <= a) ans = b;
  cout << ans << "\n";
}