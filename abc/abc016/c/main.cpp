#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int main() {
  int n, m;
  cin >> n >> m;
  int d[n][n];

  REP(i, n) {
    REP(j, n) d[i][j] = i==j ? 0 : 1e9;
  }

  int a,b;
  REP(i, m) {
    cin >> a >> b;
    a--; b--;
    d[a][b]=1;
    d[b][a]=1;
  }

  REP(i, n) {
    REP(j, n) {
      REP(k, n) d[i][j] = min(d[i][j], d[i][k]+d[k][j]);
    }
  }

  REP(i, n) {
    int ans = 0;
    REP(j, n) if (d[i][j] == 2) ans++;
    cout << ans << endl;
  }
}