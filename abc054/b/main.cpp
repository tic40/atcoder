#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
using ll = long long;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

int main() {
  int n,m; cin >> n >> m;
  string a[n],b[m];
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  REP(i,n-m+1) REP(j,n-m+1) {
    int ok = true;
    REP(k,m) REP(l,m) {
      if (a[i+k][j+l] != b[k][l]) ok = false;
    }
    if (ok) {
      cout << "Yes" << endl;
      return 0;
    }
  }

  cout << "No" << endl;
  return 0;
}