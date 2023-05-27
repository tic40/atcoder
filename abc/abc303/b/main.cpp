#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n,m; cin >> n >> m;
  vector a(m, vector<int>(n));
  REP(i,m) REP(j,n) { cin >> a[i][j]; a[i][j]--; }

  vector s(n, vector<bool>(n));
  REP(i,m) REP(j,n) {
    int now = a[i][j];
    int prev = a[i][max(0,j-1)];
    int nx = a[i][min(n-1,j+1)];
    s[now][prev] = s[now][nx] = true;
  }

  int ans = 0;
  REP(i,n) for(int j = i+1; j < n; j++) if (!s[i][j]) ans++;
  cout << ans << endl;
  return 0;
}