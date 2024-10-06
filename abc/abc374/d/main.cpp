#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;

int main() {
  int n,s,t; cin >> n >> s >> t;
  vector<int> a(n),b(n),c(n),d(n);
  REP(i,n) cin >> a[i] >> b[i] >> c[i] >> d[i];
  auto dist = [](int x, int y) -> double { return sqrt(x*x + y*y); };

  vector<int> id(n);
  iota(id.begin(),id.end(),0);
  double ans = 1e9;
  do {
    REP(bit,1<<n) {
      double tot = 0;
      int x = 0, y = 0;
      REP(i,n) {
        int idx = id[i];
        // (a,b) -> (c,d)
        if (bit >> i & 1) {
          auto d1 = dist(a[idx] - x, b[idx] - y);
          tot += d1 / s;
          auto d2 = dist(c[idx] - a[idx], d[idx] - b[idx]);
          tot += d2 / t;
          x = c[idx], y = d[idx];
        // (c,d) -> (a,b)
        } else {
          auto d1 = dist(c[idx] - x, d[idx] - y);
          tot += d1 / s;
          auto d2 = dist(c[idx] - a[idx], d[idx] - b[idx]);
          tot += d2 / t;
          x = a[idx], y = b[idx];
        }
      }
      ans = min(ans,tot);
    }
  } while (next_permutation(id.begin(), id.end()));

  printf("%.10f\n", ans);
  return 0;
}