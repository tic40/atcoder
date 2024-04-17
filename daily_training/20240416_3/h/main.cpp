#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m,l; cin >> n >> m >> l;
  vector<P> a(n),b(m);
  REP(i,n) { int x; cin >> x; a[i] = {x,i}; }
  REP(i,m) { int x; cin >> x; b[i] = {x,i}; }
  vector g(n,unordered_set<int>());
  REP(i,l) {
    int c,d; cin >> c >> d; c--; d--;
    g[c].insert(d);
  }

  sort(b.rbegin(),b.rend());
  int ans = 0;
  REP(i,n) {
    auto& st = g[a[i].second];
    REP(j,n) {
      if (st.find(b[j].second) != st.end()) continue;
      ans = max(ans, a[i].first + b[j].first);
      break;
    }
  }
  cout << ans << endl;
  return 0;
}