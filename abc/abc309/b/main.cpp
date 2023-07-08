#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> a(n);
  REP(i,n) cin >> a[i];

  auto b = a;
  REP(j,n-1) b[0][j+1] = a[0][j];
  REP(i,n-1) b[i+1][n-1] = a[i][n-1];
  for(int j = n-1; j > 0; j--) b[n-1][j-1] = a[n-1][j];
  for(int i = n-1; i > 0; i--) b[i-1][0] = a[i][0];

  REP(i,n) {
    REP(j,n) cout << b[i][j];
    cout << endl;
  }
  return 0;
}