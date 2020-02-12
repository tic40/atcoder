#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
  int n,m;
  cin >> n >> m;
  vector<string> a(n),b(m);
  REP(i,n) cin >> a[i];
  REP(i,m) cin >> b[i];

  REP(i,n-m+1) REP(j,n-m+1) {
    bool match = true;
    REP(_i,m) {
      REP(_j,m) {
        if (a[i+_i][j+_j] != b[_i][_j]) match = false;
      }
      if (!match) break;
    }
    if (match) { cout << "Yes" << endl; return 0; }
  }
  cout << "No" << endl;
}