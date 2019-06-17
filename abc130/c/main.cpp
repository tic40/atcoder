#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int w, h, x, y;
  cin >> w >> h >> x >> y;
  double ans = double(w) * double(h) / 2;
  int ans2 = 2*x == w && 2*y == h;
  printf("%f %d\n", ans, ans2);
}