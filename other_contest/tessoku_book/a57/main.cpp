#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,q; cin >> n >> q;
  vector<int> a(n);
  REP(i,n) { cin >> a[i]; a[i]--; }

  int logK = 1;
  while ((1LL << logK) <= 1e9+5) logK++;
  vector doubling(logK, vector<int> (1e5));
  REP(i,n) doubling[0][i] = a[i];

  // 前処理 doubling の計算
  REP(i,logK-1) REP(j,n) {
    doubling[i+1][j] = doubling[i][doubling[i][j]];
  }

  REP(_,q) {
    int x,y; cin >> x >> y;
    x--; y--;
    int now = a[x];
    REP(i,logK) {
      if ((y >> i) & 1) now = doubling[i][now];
    }
    cout << now+1 << endl;
  }
  return 0;
}