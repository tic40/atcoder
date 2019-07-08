#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define FOR(i, m, n) for(int i = m; i < n; i++)

int main() {
  int n, d, ans = 0;
  cin >> n >> d;
  vector<vector<int>> x(n, vector<int>(d));
  REP(i, n) REP(j, d) cin >> x[i][j];
  REP(i, n) {
    if (i == n) break;
    FOR(j, i+1, n) {
      double calc = 0;
      REP(k, d) calc += pow((double)(x[i][k] - x[j][k]), 2);
      calc = sqrt(calc);
      if (ceil(calc) == floor(calc)) ans++;
    }
  }
  cout << ans << endl;
}