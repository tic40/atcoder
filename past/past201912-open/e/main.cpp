#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define ALL(x) x.begin(), x.end()
using ll = long long;
const int INF = 1e9;
const ll LINF = 1e18;
const int MOD = 1e9+7;

vector<vector<int>> d(100, vector<int>(100));

int main() {
  int n,q;
  cin >> n >> q;

  REP(i,q) {
    int t; cin >> t;
    int x; cin >> x; x--;

    if (t == 1) {
      int y; cin >> y; y--;
      d[x][y] = 1;
    } else if (t == 2) {
      REP(j,n) {
        if (j == x) continue;
        if (d[j][x] == 1) d[x][j] = 1;
      }
    } else {
      vector<int> follows;
      REP(j,n) if (d[x][j] == 1) follows.push_back(j);
      for(int j: follows) {
        REP(k,n) {
          if (k == x) continue;
          if (d[j][k] == 1) d[x][k] = 1;
        }
      }
    }
  }

  REP(i,n) {
    REP(j,n) cout << (d[i][j] == 1 ? "Y" : "N");
    cout << endl;
  }
  return 0;
}