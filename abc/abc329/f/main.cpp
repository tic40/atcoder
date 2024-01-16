#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector c(n,unordered_set<int>());
  REP(i,n) {
    int x; cin >> x; x--;
    c[i].insert(x);
  }
  REP(_,q) {
    int a,b; cin >> a >> b;
    a--; b--;
    if (c[a].size() > c[b].size()) {
      for(auto v: c[b]) c[a].insert(v);
      swap(c[a],c[b]);
    } else {
      for(auto v: c[a]) c[b].insert(v);
    }
    cout << c[b].size() << endl;
    c[a].clear();
  }
  return 0;
}