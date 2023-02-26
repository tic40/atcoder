#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  set<P> st;
  REP(i,m) {
    int x,y; cin >> x >> y;
    x--; y--;
    st.emplace(x,y);
  }

  vector<vector<int>> g(n);
  vector<int> deg(n);
  for(auto [x,y]: st) {
    g[x].push_back(y);
    deg[y]++;
  }

  queue<int> q;
  REP(i,n) if (deg[i] == 0) q.push(i);
  vector<int> ans;

  while(q.size() == 1) {
    int v = q.front(); q.pop();
    ans.push_back(v);
    for(int nv: g[v]) {
      deg[nv]--;
      if (deg[nv] == 0) q.push(nv);
    }
  }

  if ((int)ans.size() == n) {
    vector<int> a(n);
    REP(i,n) { a[ans[i]] = i+1; }
    cout << "Yes" << endl;
    REP(i,n) cout << a[i] << " ";
    cout << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}