#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;
const int INF = 1e9;

const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,-1,0,1};

int main() {
  int h,w,ch,cw,dh,dw;
  cin >> h >> w;
  cin >> ch >> cw >> dh >> dw;
  ch--; cw--; dh--; dw--;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector d(h,vector<int>(w,INF));
  d[ch][cw] = 0;

  deque<P> dq;
  dq.emplace_back(ch,cw);

  while(dq.size()) {
    auto [x,y] = dq.front();
    dq.pop_front();

    REP(v,4) {
      int nx = x+di[v];
      int ny = y+dj[v];
      if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
      if (s[nx][ny] == '#') continue;
      if (d[nx][ny] <= d[x][y]) continue;
      d[nx][ny] = d[x][y];
      dq.emplace_front(nx,ny);
    }
    for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++) {
      int nx = x+i;
      int ny = y+j;
      if (nx < 0 || h <= nx || ny < 0 || w <= ny) continue;
      if (s[nx][ny] == '#') continue;
      if (d[nx][ny] <= d[x][y]+1) continue;
      d[nx][ny] = d[x][y]+1;
      dq.emplace_back(nx,ny);
    }
  }

  int ans = d[dh][dw];
  cout << (ans == INF ? -1 : ans) << endl;
  return 0;
}