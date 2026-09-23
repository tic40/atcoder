#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,q; cin >> n >> q;
  set<P> s;
  int ans = n;

  REP(i,q) {
    int l, r; cin >> l >> r;
    int nl = l, nr = r;

    auto it = s.lower_bound({l, -1});
    if (it != s.begin()) --it;

    while (it != s.end()) {
      auto [l,r] = *it;

      // 完全に左側
      if (r < nl - 1) { ++it; continue; }

      // 完全に右側
      if (l > nr + 1) break;

      // 重なる or 隣接する
      nl = min(nl,l);
      nr = max(nr,r);

      ans += r - l + 1;
      it = s.erase(it);
    }

    s.emplace(nl,nr);
    ans -= nr - nl + 1;
    cout << ans << endl;
  }
  return 0;
}
