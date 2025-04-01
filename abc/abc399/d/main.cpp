#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int t; cin >> t;

  auto solve = []() {
    int n; cin >> n;
    vector g(n,vector<int>());
    REP(i,n*2) {
      int a; cin >> a; a--;
      g[a].push_back(i);
    }

    set<P> st;
    for(auto v: g) if (v.size() == 2 && v[1]-v[0] > 1) {
      st.emplace(v[0],v[1]);
    }

    int ans = 0;
    for(auto [l,r]: st) {
      if (st.count(P{l+1,r+1}) || st.count(P{l+1,r-1})) ans++;
    }
    cout << ans << endl;
  };

  REP(_,t) solve();
  return 0;
}
