#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
using P = pair<int,int>;
using T = pair<int,P>;
const int INF = numeric_limits<int>::max();
const vector<int> di = {0,1,0,-1};
const vector<int> dj = {1,0,-1,0};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector dist(h,vector<int>(w,INF));
  deque<T> dq;
  dq.emplace_back(0,P(0,0));
  dist[0][0] = 0;

  while(dq.size()) {
    auto [d,pa] = dq.front(); dq.pop_front();
    auto [x,y] = pa;
    if (dist[x][y] != d) continue;

    REP(i,4) {
      int ni = x + di[i];
      int nj = y + dj[i];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '#') continue;
      if (dist[ni][nj] <= dist[x][y]) continue;
      dist[ni][nj] = dist[x][y];
      dq.emplace_front(dist[x][y], P(ni,nj));
    }

    for(int i = -2; i <= 2; i++) for(int j = -2; j <= 2; j++) {
      if (i == 0 && j == 0) continue;
      if (abs(i) + abs(j) > 3) continue;
      int ni = x + i;
      int nj = y + j;
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (dist[ni][nj] <= dist[x][y]+1) continue;
      dist[ni][nj] = dist[x][y]+1;
      dq.emplace_back(dist[x][y]+1, P(ni,nj));
    }
  }

  cout << dist[h-1][w-1] << endl;
  return 0;
}