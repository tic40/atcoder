#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int main() {
  int n; cin >> n;
  vector<int> x(n),y(n),h(n);
  REP(i,n) cin >> x[i] >> y[i] >> h[i];

  int ti = -1;
  REP(i,n) if (h[i] > 0) { ti = i; break; }

  REP(cx,101) REP(cy,101) {
    int th = h[ti] + abs(x[ti]-cx) + abs(y[ti]-cy);

    bool ok = [&]() {
      REP(i,n) {
        if (h[i] != max(0, th - abs(x[i]-cx) - abs(y[i]-cy))) return false;
      }
      return true;
    }();

    if (ok) {
      cout << cx << " " << cy << " " << th << endl;
      return 0;
    }
  }
  return 0;
}
