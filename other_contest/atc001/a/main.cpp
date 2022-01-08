#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
using ll = long long;
using P = pair<int,int>;
vector<P> moves = { {0,1},{0,-1},{1,0},{-1,0} };

int main() {
  int h,w; cin >> h >> w;
  char c[h][w];
  vector<P> q;
  REP(i,h) REP(j,w) { cin >> c[i][j]; if(c[i][j] == 's') q.push_back({i,j}); }

  while(!q.empty()) {
    P t = q.back(); q.pop_back();
    char current = c[t.first][t.second];
    if (current == 'g') { cout << "Yes" << endl; return 0; }
    if (current == '#' || current == 'v') continue;
    c[t.first][t.second] = 'v'; // visited

    for(P m : moves) {
      int y = t.first+m.first, x = t.second+m.second;
      if (y >= 0 && y < h && x >= 0 && x < w) q.push_back({y,x});
    }
  }
  cout << "No" << endl;
  return 0;
}