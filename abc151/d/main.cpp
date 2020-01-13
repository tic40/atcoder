#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

const int INF = 1001001001;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int h, w, ans=0;
  cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  // 始点 si, sj
  REP(si,h) {
    REP(sj,w) {
      if (s[si][sj] == '#') continue;
      vector<vector<int>> dist(h, vector<int>(w, INF));
      queue<pair<int, int>> q;
      // func
      auto update = [&](int i, int j, int x) {
        if (dist[i][j] != INF) return;
        dist[i][j] = x;
        q.push(make_pair(i,j));
      };
      update(si, sj, 0);
      while(!q.empty()) {
        int i = q.front().first;
        int j = q.front().second;
        q.pop();
        REP(dir,4) {
          int ni = i+di[dir];
          int nj = j+dj[dir];
          if (ni<0||ni>=h||nj<0||nj>=w) continue;
          if (s[ni][nj] == '#') continue;
          update(ni,nj,dist[i][j]+1);
        }
      }
      REP(i,h) {
        REP(j,w) {
          if (dist[i][j] == INF) continue;
          ans = max(ans, dist[i][j]);
        }
      }
    }
  }
  cout << ans << endl;
}