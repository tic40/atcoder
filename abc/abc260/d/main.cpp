#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;

  set<int> st;
  vector<vector<int>> g(n);
  vector<int> ans(n,-1);
  REP(i,n) {
    int p; cin >> p;
    p--;

    auto it = st.upper_bound(p);
    if(it == st.end()) {
      st.insert(p);
    } else {
      swap(g[*it],g[p]);
      st.erase(*it);
      st.insert(p);
    }

    g[p].push_back(p);
    if ((int)g[p].size() == k) {
      for(int v: g[p]) ans[v] = i+1;
      st.erase(p);
    }
  }

  for(int v: ans) cout << v << endl;
  return 0;
}