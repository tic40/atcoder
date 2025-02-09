#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  dsu uf(n);
  vector<tuple<int,int,int>> t;
  REP(i,m) {
    int a,b; cin >> a >> b; a--; b--;
    if (uf.same(a,b)) t.emplace_back(i,a,b);
    else uf.merge(a,b);
  }

  unordered_set<int> st;
  auto g = uf.groups();
  for(auto group: g) st.insert(uf.leader(group[0]));

  vector<tuple<int,int,int>> ans;
  for(auto [i,a,b]: t) {
    for(auto v: st) if (uf.leader(a) != uf.leader(v)) {
      uf.merge(a,v);
      ans.emplace_back(i+1,a+1,v+1);
      st.erase(v);
      break;
    }
  }

  cout << ans.size() << endl;
  for(auto [i,a,b]: ans) printf("%d %d %d \n",i,a,b);
  return 0;
}
