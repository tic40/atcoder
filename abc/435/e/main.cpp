#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  map<int,int> mp;
  int ans = n;
  REP(_,q) {
    int l,r; cin >> l >> r;
    int nl = l, nr = r;
    auto it = mp.lower_bound(l);
    if (it != mp.begin()) --it;

    while(it != mp.end()) {
      l = it->first;
      r = it->second;

      if (r+1 < nl) { ++it; continue; }
      if (nr < l-1) break;

      nl = min(nl,l);
      nr = max(nr,r);
      it = mp.erase(it);
      ans += r-l+1;
    }
    mp[nl] = nr;
    ans -= nr-nl+1;
    cout << ans << endl;
  }
  return 0;
}
