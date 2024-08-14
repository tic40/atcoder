#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> s(n),t(n);
  REP(i,n) cin >> s[i];
  REP(i,n) cin >> t[i];

  auto move_origin = [&](vector<string>& s) -> void {
    int ml = INF, mt = INF;
    REP(i,n) REP(j,n) if (s[i][j] == '#') {
      mt = min(mt,i); ml = min(ml,j);
    }
    REP(i,n) REP(j,n) if (s[i][j] == '#') {
      s[i][j] = '.';
      s[i-mt][j-ml] = '#';
    }
  };

  f(s);
  bool ok = false;
  REP(i,4) {
    auto tn = t;
    REP(i,n) REP(j,n) tn[i][j] = t[n-1-j][i];
    move_origin(tn);
    if (s == tn) ok = true;
    swap(tn,t);
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}