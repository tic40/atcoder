#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector b(n,vector<int>(m));
  REP(i,n) REP(j,m) { cin >> b[i][j]; b[i][j]--; }

  auto f = [&]() -> bool {
    REP(i,n) {
      for(int j = 1; j < m; j++) if (b[i][j] != b[i][j-1]+1) return false;
      if (b[i][0] / 7 != b[i].back() / 7) return false;
    }
    REP(j,m) for(int i = 1; i < n; i++) if (b[i][j] != b[i-1][j]+7) return false;

    return true;
  };
  cout << (f() ? "Yes" : "No") << endl;
  return 0;
}