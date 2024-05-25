#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,t; cin >> n >> t;
  vector<int> a(t);
  REP(i,t) { cin >> a[i]; a[i]--; }
  vector v(n,vector<int>(n));

  auto bingo = [&](int x, int y) {
    v[x][y] = 1;
    // 横
    bool ok = true;
    REP(i,n) if (v[y][i] == 0) { ok = false; break; }
    if (ok) return true;

    // 縦
    ok = true;
    REP(i,n) if (v[i][x] == 0) { ok = false; break; }
    if (ok) return true;

    ok = true;
    REP(i,n) if (v[i][i] == 0) { ok = false; break; }
    if (ok) return true;

    ok = true;
    REP(i,n) if (v[n-i-1][i] == 0) { ok = false; break; }
    if (ok) return true;

    return false;
  };

  REP(i,t) {
    int y = a[i] / n;
    int x = a[i] % n;
    if (bingo(x,y)) { cout << i+1 << endl; return 0; }
  }

  cout << -1 << endl;
  return 0;
}