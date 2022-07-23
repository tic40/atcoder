#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using ll = long long;

int main() {
  int n; cin >> n;
  vector<string> a(n);
  REP(i,n) cin >> a[i];

  bool ok = true;
  REP(i,n) REP(j,n) {
    if (a[i][j] == 'W') {
      if (a[j][i] != 'L') ok = false;
    } else if (a[i][j] == 'L') {
      if (a[j][i] != 'W') ok = false;
    } else if (a[i][j] == 'D') {
      if (a[j][i] != 'D') ok = false;
    }
  }

  cout << (ok ? "correct" : "incorrect") << endl;
  return 0;
}