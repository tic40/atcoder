#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int h,w; cin >> h >> w;
  vector x(h,vector<int>(w));
  REP(i,h) REP(j,w) cin >> x[i][j];

  vector s(h+1,vector<int>(w+1));
  REP(i,h) REP(j,w) s[i+1][j+1] = x[i][j];
  REP(i,h) REP(j,w) s[i+1][j+1] += s[i+1][j];
  REP(i,h) REP(j,w) s[i+1][j+1] += s[i][j+1];

  int q; cin >> q;
  REP(_,q) {
    int a,b,c,d;
    cin >> a >> b >> c >> d;
    int ans = s[c][d];
    ans -= s[a-1][d];
    ans -= s[c][b-1];
    ans += s[a-1][b-1];
    cout << ans << endl;
  }
  return 0;
}