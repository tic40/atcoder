#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int t; cin >> t;

  auto solve = []() {
    int n; cin >> n;
    vector<P> pos(n,{-1,-1});
    REP(i,n*2) {
      int a; cin >> a; a--;
      pos[a].first == -1 ? pos[a].first = i : pos[a].second = i;
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

