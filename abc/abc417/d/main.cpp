#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<int> p(n),a(n),b(n);
  REP(i,n) cin >> p[i] >> a[i] >> b[i];

  auto binary_search = [&]() {
    int ok = 1e8, ng = 0;
    while(ok-ng>1) {
      int mid = (ok+ng)/2;
      auto f = [&](int x) {
        REP(i,n) {
          if (p[i] > x) return false;
          x -= b[i];
        }
        return true;
      };
      f(mid) ? ok = mid : ng = mid;
    }
    return ok;
  };

  int upper = binary_search();
  int sb = accumulate(b.begin(),b.end(),0);
  map<int,int> mp;

  auto solve = [&](int x) {
    if (x >= upper) return x-sb;
    if (mp.count(x)) return mp[x];
    int now = x;
    REP(i,n) now <= p[i] ? now += a[i] : now = max(0,now-b[i]);
    return mp[x] = now;
  };

  int q; cin >> q;
  REP(_,q) {
    int x; cin >> x;
    cout << solve(x) << endl;
  }
  return 0;
}