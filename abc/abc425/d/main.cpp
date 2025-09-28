#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  queue<P> q,nq;
  vector visited(h,vector<int>(w));
  REP(i,h) REP(j,w) if (s[i][j] == '#') q.emplace(i,j);

  int ans = 0;
  while(q.size()) {
    while(q.size()) {
      auto [i,j] = q.front(); q.pop();
      ans++;
      s[i][j] = '#';
      REP(k,4) {
        int ni = i+di[k], nj = j+dj[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (s[ni][nj] == '#') continue;
        nq.emplace(ni,nj);
      }
    }
    while(nq.size()) {
      auto [i,j] = nq.front(); nq.pop();
      if (visited[i][j]) continue;
      visited[i][j] = 1;
      int cnt = 0;
      REP(k,4) {
        int ni = i+di[k], nj = j+dj[k];
        if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
        if (s[ni][nj] == '#') cnt++;
      }
      if (cnt == 1) q.emplace(i,j);
    }
  }
  cout << ans << endl;
  return 0;
}