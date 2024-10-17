#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'

int main() {
  int n; cin >> n;
  vector<string> a(n);
  REP(i,n) cin >> a[i];

  // O(N^3) TLE
  auto solve1 = [&]() -> void {
    for(int k = 0; k <= n/2; k++) {
      auto p = a;
      for(int x = k; x <= n-1-k; x++) for(int y = k; y <= n-1-k; y++) {
        a[y][n-1-x] = p[x][y];
      }
    }
    REP(i,n) cout << a[i] << endl;
  };

  // O(N^2)
  auto solve2 = [&]() -> void {
    auto p = a;
    REP(i,n) REP(j,n) {
      int ni = i, nj = j;
      int k = min({ni+1,nj+1,n-ni,n-nj}) % 4; // 何回90度回転させるか
      REP(_,k) { swap(ni,nj); nj = n-1-nj; }
      a[ni][nj] = p[i][j];
    }
    REP(i,n) cout << a[i] << endl;
  };

  // solve1();
  solve2();
  return 0;
}