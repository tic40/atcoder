#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int main() {
  int n,k; cin >> n >> k;
  vector m(5001, vector<int>(5001));
  REP(i,n) {
    int a,b; cin >> a >> b;
    m[a][b]++;
  }

  REP(i,5000) REP(j,5000) {
    m[i+1][j+1] += m[i+1][j];
    m[i+1][j+1] += m[i][j+1];
    m[i+1][j+1] -= m[i][j];
  }

  int ans = 0;
  REP(i,5001-k) REP(j,5001-k) {
    int ri = min(5000, i+k+1);
    int rj = min(5000, j+k+1);
    int now = m[ri][rj];
    now -= m[ri][j];
    now -= m[i][rj];
    now += m[i][j];
    ans = max(ans,now);
  }
  cout << ans << endl;
  return 0;
}