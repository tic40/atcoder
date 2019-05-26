#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;
#define INF 100000000

int main() {
  int n, m, l, r, left = 0, right = INF;
  cin >> n >> m;
  vector<vector<int>> data(m, vector<int>(2));
  REP(i, m) cin >> data[i][0] >> data[i][1];
  REP(i, m) {
    l = data[i][0]; r = data[i][1];
    if (r < left || right < l) { cout << 0 << "\n"; return 0; }
    left = max(left, l); right = min(right, r);
  }
  cout << (right - left + 1) << "\n";
}