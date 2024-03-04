#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  string s; cin >> s;
  vector<int> c(n);
  REP(i,n) { cin >> c[i]; c[i]--; }
  vector g(m,vector<int>());
  REP(i,n) g[c[i]].push_back(i);

  auto t = s;
  REP(i,m) {
    int sz = g[i].size();
    REP(j,sz) t[g[i][(j+1)%sz]] = s[g[i][j]];
  }
  cout << t << endl;
  return 0;
}