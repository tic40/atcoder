#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<int> p(n),c(n);
  vector f(n,vector<bool>(m));
  REP(i,n) {
    cin >> p[i] >> c[i];
    REP(j,c[i]) {
      int x; cin >> x; x--;
      f[i][x] = true;
    }
  }

  REP(i,n) REP(j,n) {
    if (i == j) continue;
    if (p[i] > p[j]) continue;
    bool ok = true;
    int cnt = 0; // i のみにある機能の個数
    REP(k,m) {
      if (f[j][k] && !f[i][k]) ok = false;
      if (f[i][k] && !f[j][k]) cnt++;
    }
    if (p[i] == p[j]) ok = ok && cnt > 0;
    if (ok) { cout << "Yes" << endl; return 0; }
  }

  cout << "No" << endl;
  return 0;
}