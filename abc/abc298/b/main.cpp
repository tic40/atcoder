#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector a(n,vector<int>(n));
  vector b(n,vector<int>(n));
  REP(i,n) REP(j,n) cin >> a[i][j];
  REP(i,n) REP(j,n) cin >> b[i][j];

  REP(_,4) {
    vector an(n,vector<int>(n));
    REP(i,n) REP(j,n) an[i][j] = a[n-1-j][i];
    bool ok = true;
    REP(i,n) REP(j,n) {
      if (a[i][j] != 1) continue;
      if (b[i][j] != 1) ok = false;
    }
    if (ok) { cout << "Yes" << endl; return 0; }
    swap(an,a);
  }
  cout << "No" << endl;
  return 0;
}