#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n, q; cin >> n;

  vector<vector<vector<int>>> a(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      for (int z = 1; z <= n; ++z) {
        cin >> a[x][y][z];
      }
    }
  }

  vector<vector<vector<int>>> s(n + 1, vector<vector<int>>(n + 1, vector<int>(n + 1, 0)));
  for (int x = 1; x <= n; ++x) {
    for (int y = 1; y <= n; ++y) {
      for (int z = 1; z <= n; ++z) {
        s[x][y][z] = a[x][y][z]
          + s[x-1][y][z]
          + s[x][y-1][z]
          + s[x][y][z-1]
          - s[x-1][y-1][z]
          - s[x-1][y][z-1]
          - s[x][y-1][z-1]
          + s[x-1][y-1][z-1];
      }
    }
  }

  cin >> q;
  REP(_,q) {
    int lxi, rxi, lyi, ryi, lzi, rzi;
    cin >> lxi >> rxi >> lyi >> ryi >> lzi >> rzi;

    int sum = s[rxi][ryi][rzi]
      - s[lxi-1][ryi][rzi]
      - s[rxi][lyi-1][rzi]
      - s[rxi][ryi][lzi-1]
      + s[lxi-1][lyi-1][rzi]
      + s[lxi-1][ryi][lzi-1]
      + s[rxi][lyi-1][lzi-1]
      - s[lxi-1][lyi-1][lzi-1];

    cout << sum << endl;
  }
  return 0;
}