#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
typedef long long ll;

int h, w, ans = 0;
char _;
queue<pair<int, int>> q;
vector<vector<int>> moves = { { 1, 0 }, { -1, 0 }, { 0, 1 }, { 0, -1 } };

int main() {
  cin >> h >> w;
  vector<vector<int>> memo(h, vector<int>(w, -1));
  REP(i, h) REP(j, w) {
    cin >> _;
    if (_ == '#') {
      q.push(make_pair(i, j)); memo[i][j] = 0;
    }
  }
  while(!q.empty()) {
    auto front = q.front();
    q.pop();
    int x = front.first, y = front.second;
    for (auto move: moves) {
      int nx = x + move[0], ny = y + move[1];
      if (nx < 0 || ny < 0 || nx >= h || ny >= w || memo[nx][ny] >= 0) continue;
      memo[nx][ny] = memo[x][y] + 1;
      q.push(make_pair(nx, ny));
    }
  }
  REP(i, h) REP(j, w) ans = max(ans, memo[i][j]);
  cout << ans << "\n";
}