#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)

int main() {
  int n; cin >> n;
  vector<vector<int>> g(n+1);
  REP(i,n) {
    int a; cin >> a;
    g[a].push_back(i);
  }

  int q; cin >> q;
  REP(i,q) {
    int l,r,x; cin >> l >> r >> x;
    l--; r--;
    auto it1 = lower_bound(g[x].begin(),g[x].end(),l);
    auto it2 = upper_bound(g[x].begin(),g[x].end(),r) - 1;
    cout << it2 - it1 + 1 << endl;
  }
  return 0;
}