#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using P = pair<int, int>;

vector<P> moves = { {0,1}, {0,-1}, {1,0}, {-1,0} };
int main() {
  int h,w; cin >> h >> w;
  P s, g;
  cin >> s.first >> s.second;
  cin >> g.first >> g.second;
  s.first--; s.second--; g.first--; g.second--;
  queue<P> q;
  q.push(s);

  string str;
  int a[h][w];
  REP(i,h) {
    cin >> str;
    REP(j,w) a[i][j] = str[j] == '.' ? 0 : -1;
  }

  while(!q.empty()) {
    P t = q.front(); q.pop();
    int c = a[t.first][t.second];
    if (t == g) { cout << c << endl; return 0; }

    for (P m : moves) {
      int ny = m.first + t.first, nx = m.second + t.second;
      if (ny >= 0 && ny < h && nx >= 0 && nx < w && a[ny][nx] == 0) {
        a[ny][nx]+=c+1;
        q.push({ny,nx});
      }
    }
  }
  return 0;
}