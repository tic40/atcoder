#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

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
      st.insert(now);
      g[now].push_back(now);
    } else {
      g[*it].push_back(now);
      swap(g[*it],g[now]);
      st.erase(*it);
      st.insert(now);
    }

    if ((int)g[now].size() == k) {
      for(auto v: g[now]) ans[v] = i+1;
      st.erase(now);
    }
  }

  for(int v: ans) cout << v << endl;
  return 0;
}