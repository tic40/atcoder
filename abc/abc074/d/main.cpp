#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];

  vector r(n,vector<bool>(n,true)); // r[i][j] := i-j間に道路が必要かどうか
  REP(k,n) REP(i,n) REP(j,n) {
    if (k == i || k == j || i == j) continue;
    int d1 = a[i][k] + a[k][j];
    int d2 = a[i][j];

    // d1が最短経路じゃない場合は矛盾
    if (d1 < d2) {
      cout << -1 << endl;
      return 0;
    }
    // 距離が同じ場合は道路は不要
    if (d1 == d2) r[i][j] = false;
  }

  ll ans = 0;
  REP(i,n) for(int j = i+1; j < n; j++) {
    if (r[i][j]) ans += a[i][j];
  }
  cout << ans << endl;
  return 0;
}