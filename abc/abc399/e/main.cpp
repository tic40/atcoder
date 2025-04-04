#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  auto solve = []() {
    int n; cin >> n;
    string s,t; cin >> s >> t;
    const int m = 26;

    if (s==t) return 0;

    {
      set<char> st(t.begin(),t.end());
      if (st.size() == m) return -1;
    }

    set<P> edges;
    REP(i,n) edges.emplace(s[i]-'a', t[i]-'a');
    vector<int> in_deg(m),out_deg(m);
    for(auto e: edges) {
      out_deg[e.first]++;
      in_deg[e.second]++;
    }

    REP(i,m) if (out_deg[i] > 1) return -1;

    int ans = edges.size();
    scc_graph g(m);
    for(auto [a,b]: edges) {
      if (a==b) ans--;
      else g.add_edge(a,b);
    }

    for(auto group: g.scc()) {
      if (group.size() >= 2) {
        bool br = false;
        for(int v: group) if (in_deg[v] > 1) br = true;
        if (!br) ans++;
      }
    }
    return ans;
  };

  cout << solve() << endl;
  return 0;
}
