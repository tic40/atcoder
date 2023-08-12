#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  int n; cin >> n;
  vector g(n,vector<int>(37));
  vector<int> c(n);
  REP(i,n) {
    cin >> c[i];
    REP(j,c[i]) {
      int a; cin >> a;
      g[i][a] = 1;
    }
  }
  int x; cin >> x;

  vector<P> p;
  REP(i,n) {
    if (g[i][x] == 0) continue;
    p.emplace_back(c[i],i);
  }
  sort(p.begin(),p.end());
  vector<int> ans;
  for(auto [k,v]: p) {
    if (k > p[0].first) break;
    ans.push_back(v);
  }
  cout << ans.size() << endl;
  for(auto v: ans) cout << v+1 << " ";
  return 0;
}