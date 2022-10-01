#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<vector<int>> g(n);
  REP(i,n) {
    int l; cin >> l;
    REP(j,l) {
      int x; cin >> x;
      g[i].push_back(x);
    }
  }

  REP(i,q) {
    int s,t; cin >> s >> t;
    s--; t--;
    cout << g[s][t] << endl;
  }
  return 0;
}