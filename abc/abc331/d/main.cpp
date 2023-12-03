#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,q; cin >> n >> q;
  vector<string> p(n);
  REP(i,n) cin >> p[i];

  vector s(n+1,vector<int>(n+1));
  REP(i,n) REP(j,n) s[i+1][j+1] = p[i][j] == 'B' ? 1 : 0;
  REP(i,n) REP(j,n) s[i+1][j+1] += s[i+1][j];
  REP(i,n) REP(j,n) s[i+1][j+1] += s[i][j+1];

  auto f = [&](int c, int d) {
    // 右下
    ll res = s[c%n][d%n];
    // 周期分
    res += s[n][n] * ll(c/n) * (d/n);
    // 縦に長い方
    res += s[n][d%n] * ll(c/n);
    // 横に長い方
    res += s[c%n][n] * ll(d/n);
    return res;
  };

  REP(_,q) {
    int a,b,c,d; cin >> a >> b >> c >> d;
    c++; d++;
    ll ans = f(c,d) - f(c,b) - f(a,d) + f(a,b);
    cout << ans << endl;
  }
  return 0;
}