#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,s,t; cin >> n >> s >> t;
  vector<P> a(n),b(n);
  REP(i,n) cin >> a[i].first >> a[i].second >> b[i].first >> b[i].second;

  vector<int> id(n);
  iota(id.begin(),id.end(),0);
  double ans = 1e9;
  do {
    REP(bit,1<<n) {
      double tot = 0;
      int x = 0, y = 0;
      REP(i,n) {
        int idx = id[i];
        if (bit >> i & 1) swap(a[idx],b[idx]);
        tot += hypot(a[idx].first - x, a[idx].second - y) / s;
        tot += hypot(b[idx].first - a[idx].first, b[idx].second - a[idx].second) / t;
        x = b[idx].first, y = b[idx].second;
        if (bit >> i & 1) swap(a[idx],b[idx]);
      }
      ans = min(ans,tot);
    }
  } while (next_permutation(id.begin(), id.end()));

  printf("%.10f\n", ans);
  return 0;
}