#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;

int n;
vector<int> x,y,h;

void solve() {
  int si = -1;
  REP(i,n) {
    if (h[i] > 0) { si = i; break; }
  }

  // cx, cy を全探索する
  REP(cx,101) REP(cy,101) {
    ll ch = h[si] + abs(cx - x[si]) + abs(cy - y[si]);

    bool ok = true;
    REP(i,n) {
      ll tmp = abs(cx - x[i]) + abs(cy - y[i]);
      if (h[i] > 0 && ch - h[i] != tmp) ok = false;
      if (h[i] == 0 && ch > tmp) ok = false;
    }

    if (ok) {
      cout << cx << " " << cy << " " << ch << endl;
      return;
    }
  }

  return;
}

int main() {
  cin >> n;
  x.resize(n);
  y.resize(n);
  h.resize(n);
  REP(i,n) cin >> x[i] >> y[i] >> h[i];

  solve();
  return 0;
}