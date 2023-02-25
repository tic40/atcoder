#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector g(n,vector<int>());
  REP(i,m) {
    int a,b; cin >> a >> b;
    a--; b--;
    g[a].push_back(b);
    g[b].push_back(a);
  }

  REP(i,n) {
    cout << i+1 << ": {";
    REP(j,(int)g[i].size()) {
      if (j != 0) cout << ", ";
      cout << g[i][j]+1;
    }
    cout << "}" << endl;
  }
  return 0;
}