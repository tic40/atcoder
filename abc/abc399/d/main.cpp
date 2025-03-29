#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int t; cin >> t;

  auto solve = []() {
    int n; cin >> n;
    int n2 = n*2;
    vector<int> a(n2);
    REP(i,n2) { cin >> a[i]; a[i]--; }

    vector<P> pos(n,{-1,-1});
    REP(i,n2) {
      if (pos[a[i]].first == -1) pos[a[i]].first = i;
      else pos[a[i]].second = i;
    }

    set<P> st;
    for(auto [l,r]: pos) if (l+1 != r) st.emplace(l,r);

    int ans = 0;
    for(auto [l,r]: st) {
      if (st.count(P{l+1,r+1}) || st.count(P{l+1,r-1})) ans++;
    }
    cout << ans << endl;
  };

  REP(_,t) solve();
  return 0;
}
