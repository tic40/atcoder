#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  int l = 0, r = 1;
  auto f = [&](int dir, int pos, int t)  {
    int cost = 0;
    while(pos != t) {
      if (pos == r) { cost = 1e9; break; }
      cost++;
      pos = ((pos+dir) % n + n) % n;
    }
    return cost;
  };

  int ans = 0;
  REP(_,q) {
    char h; int t; cin >> h >> t; t--;
    if (h == 'R') swap(l,r);
    ans += min(f(1,l,t),f(-1,l,t));
    l = t;
    if (h == 'R') swap(l,r);
  }
  cout << ans << endl;
  return 0;
}