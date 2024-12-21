#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;

int main() {
  map<char,P> moves;
  moves['U'] = { -1, 0 };
  moves['R'] = { 0, 1 };
  moves['D'] = { 1, 0 };
  moves['L'] = { 0, -1 };

  int h,w,x,y; cin >> h >> w >> x >> y; x--; y--;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  string t; cin >> t;

  int cnt = 0;
  for(auto c: t) {
    auto [dx,dy] = moves[c];
    x += dx; y += dy;
    if (s[x][y] == '#') { x -= dx; y -= dy; }
    if (s[x][y] == '@') { cnt++; s[x][y] = '.'; }
  }
  cout << x+1 << " " << y+1 << " " << cnt << endl;
  return 0;
}