#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for (int i = 0; i < (n); ++i)

int main() {
  const vector<int> di = {0, 1, 1, -1};
  const vector<int> dj = {1, 0, 1, 1};
  int n; cin >> n;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  bool ok = false;
  REP(i,n) REP(j,n) REP(v,4) {
    int ni = i, nj = j, cnt = 0;
    REP(k,6) {
      if (ni < 0 || nj < 0 || ni >= n || nj >= n) { cnt = 0; break; }
      if (s[ni][nj] == '#') cnt++;
      ni += di[v]; nj += dj[v];
    }
    ok = ok || cnt >= 4;
  }
  cout << (ok ? "Yes" : "No") << endl;
  return 0;
}