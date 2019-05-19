#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  bool ans = false;
  int x0, y0, xb, yb, t, v, n;
  cin >> x0 >> y0 >> xb >> yb >> t >> v >> n;
  int dist, x, y, cost = t * v;
  REP(i, n) {
    cin >> x >> y;
    dist = sqrt(pow(x - xb, 2) + pow(y - yb, 2)) + sqrt(pow(x - x0, 2) + pow(y - y0, 2));
    if (dist <= cost) {
      ans = true; break;
    }
  }
  cout << (ans ? "YES" : "NO") << "\n";
}