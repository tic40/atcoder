#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;

int main() {
  int n,m; cin >> n >> m;
  vector b(n,vector<int>(m));
  REP(i,n) REP(j,m) cin >> b[i][j];

  auto f = [&]() {
    REP(i,n-1) REP(j,m-1) {
      int d = b[i][j+1] - b[i][j];
      if (d != 1) return false;
    }
    REP(j,m) REP(i,n-1) {
      int d = b[i+1][j] - b[i][j];
      if (d != 7) return false;
    }
    REP(i,n) REP(j,m-1) {
      if (b[i][j] % 7 == 0 ) return false;
    }
    return true;
  };

  cout << (f() ? "Yes" : "No") << endl;
  return 0;
}