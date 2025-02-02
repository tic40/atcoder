#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector<string> s(n);
  REP(i,n) cin >> s[i];
  vector<string> t(m);
  REP(i,m) cin >> t[i];

  auto f = [&](int x, int y) {
    REP(i,m) REP(j,m) if (s[x+i][y+j] != t[i][j]) return false;
    return true;
  };

  REP(i,n-m+1) REP(j,n-m+1) if (f(i,j)) {
    cout << i+1 << " " << j+1 << endl;
  }
  return 0;
}