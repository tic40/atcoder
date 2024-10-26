#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  const int n = 8;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  vector m(n,vector<int>(n,1));
  REP(i,n) REP(j,n) if (s[i][j] == '#') {
    REP(i2,n) m[i2][j]=0;
    REP(j2,n) m[i][j2]=0;
  }

  int ans = 0;
  REP(i,n) REP(j,n) ans += m[i][j];
  cout << ans << endl;
  return 0;
}