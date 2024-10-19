#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  int l = 0, r = 1;
  auto f = [&](int dir, int pos, int t) -> pair<int,int> {
    int cost = 0;
    while(pos != t) {
      if (pos == r) { return { 1e9, -1 }; }
      if (pos == t) break;
      cost++;
      pos += dir;
      pos = (pos % n + n) % n;
    }
    return { cost, pos };
  };

  int ans = 0;
  REP(_,q) {
    char h; int t;
    cin >> h >> t; t--;
    if (h == 'R') swap(l,r);
    auto [cost,pos] = min(f(1,l,t),f(-1,l,t));
    l = pos; ans += cost;
    if (h == 'R') swap(l,r);
  }
  cout << ans << endl;
  return 0;
}