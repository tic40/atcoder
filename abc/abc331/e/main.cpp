#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m,l; cin >> n >> m >> l;
  vector<int> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  auto solve1 = [&]() {
    set<P> st;
    REP(i,l) {
      int c,d; cin >> c >> d;
      c--; d--;
      st.insert(P{c,d});
    }

    vector<P> pb(m);
    REP(i,m) pb[i] = { b[i], i };
    sort(pb.rbegin(),pb.rend());

    int ans = 0;
    REP(i,n) {
      for(auto [v,k]: pb) {
        if (st.find({i,k}) != st.end()) continue;
        ans = max(ans,a[i]+v);
        break;
      }
    }
    cout << ans << endl;
  };

  auto solve2 = [&]() {
    vector g(n,vector<int>());
    REP(i,l) {
      int c,d; cin >> c >> d;
      c--; d--;
      g[c].push_back(d);
    }
    multiset<int> mset;
    REP(i,m) mset.insert(b[i]);

    int ans = 0;
    REP(i,n) {
      vector<int> erased;
      for(auto v: g[i]) {
        mset.erase(b[v]);
        erased.push_back(b[v]);
      }
      if (mset.size() > 0) ans = max(ans, a[i] + *mset.rbegin());
      for(auto v: erased) mset.insert(v);
    }
    cout << ans << endl;
  };

  solve1();
  // solve2();
  return 0;
}