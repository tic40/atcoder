#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n,m; cin >> n >> m;
  set<P> st;
  REP(i,m) {
    int u,v; cin >> u >> v;
    if (u == v) continue;
    if (u > v) swap(u,v);
    st.emplace(u,v);
  }
  cout << m - st.size() << endl;
  return 0;
}
