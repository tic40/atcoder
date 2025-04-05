#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const int INF = numeric_limits<int>::max();
using P = pair<int,int>;
const vector<int> di = {-1,0,1,0};
const vector<int> dj = {0,1,0,-1};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];
  int a,b,c,d; cin >> a >> b >> c >> d;
  a--; b--; c--; d--;

  vector dist(h,vector<int>(w,INF));
  deque<P> q;
  q.emplace_front(a,b);
  dist[a][b] = 0;
  while(q.size()) {
    auto [i,j] = q.front(); q.pop_front();
    int nd = dist[i][j];

    REP(k,4) {
      int ni = i+di[k];
      int nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;

      if (s[ni][nj] == '.') {
        if (dist[ni][nj] > nd) {
          dist[ni][nj] = nd;
          q.emplace_front(ni,nj);
        }
        continue;
      }

      if (dist[ni][nj] > nd+1) {
        dist[ni][nj] = nd+1;
        q.emplace_back(ni,nj);
      }
      ni += di[k];
      nj += dj[k];
      if (ni >= 0 && nj >= 0 && ni < h && nj < w) {
        if (dist[ni][nj] > nd+1) {
          dist[ni][nj] = nd+1;
          q.emplace_back(ni,nj);
        }
      }
    }
  }
  cout << dist[c][d] << endl;
  return 0;
}
