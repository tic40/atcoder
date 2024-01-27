#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> q(n),a(n),b(n);;
  REP(i,n) cin >> q[i];
  REP(i,n) cin >> a[i];
  REP(i,n) cin >> b[i];

  int ans = 0;
  auto f = [&]() -> void {
    REP(ai,1e6+1) { // i: A を作る数
      auto t = q;
      REP(j,n) t[j] -= a[j]*ai;
      REP(j,n) if (t[j] < 0) return;

      int bi = 1e9;
      REP(j,n) if (b[j] > 0) bi = min(bi, t[j] / b[j]);
      ans = max(ans,ai+bi);
    }
  };

  f();
  cout << ans << endl;
  return 0;
}