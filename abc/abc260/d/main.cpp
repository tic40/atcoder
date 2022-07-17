#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n,k; cin >> n >> k;
  vector<int> p(n);
  REP(i,n) { cin >> p[i]; p[i]--; }

  set<int> st;
  vector<vector<int>> g(n);
  vector<int> ans(n,-1);

  REP(i,n) {
    int now = p[i];
    auto it = st.upper_bound(now);

    if(it == st.end()) {
      if (k == 1) ans[now] = i+1;
      else {
        st.insert(now);
        g[now].push_back(now);
      }
      continue;
    }

    int t = *it; // 場にある対象のカード番号
    g[t].push_back(now);
    if ((int)g[t].size() == k) {
      for(auto v: g[t]) ans[v] = i+1;
      st.erase(t);
    } else {
      swap(g[t],g[now]);
      st.erase(t);
      st.insert(now);
    }
  }

  for(int v: ans) cout << v << endl;
  return 0;
}