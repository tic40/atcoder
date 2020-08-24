#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i, n) for(int i=0;i<n;i++)
#define YES(x) cout<<(x?"YES":"NO")<<"\n"
#define Yes(x) cout<<(x?"Yes":"No")<<"\n"
#define dump(x) cout<<#x<<" = "<<(x)<<"\n"
#define endl "\n"
using G = vector<vector<int>>;
using M = map<int,int>;
using P = pair<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int,vector<int>,greater<int>>;
using V = vector<int>;
using ll = long long;
using edge = struct { int to; int cost; };
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

vector<string> s(1000);
int dist[1010][1010];
int h, w, ch, cw, dh, dw;
vector<P> moves = { {-1, 0}, {1, 0}, {0, -1}, {0, 1} };

bool is_range(int y, int x) {
  return 0 <= y && 0 <= x && y < h && x < w;
}
bool is_wall(int y, int x) {
  return s[y][x] == '#';
}
bool already_visited(int y, int x, int d) {
  return dist[y][x] <= d;
}
bool is_goal(int y, int x) {
  return y == dh && x == dw;
}

// 0-1 BFS
void bfs() {
  deque<P> d;
  d.push_back({ ch, cw });

  while(!d.empty()) {
    auto v = d.front(); d.pop_front();
    int y = v.first, x = v.second;
    int nd = dist[y][x];
    int ndd = nd+1;
    for(auto move:  moves) {
      int ny = y + move.first;
      int nx = x + move.second;

      if (!is_range(ny, nx)) continue;
      if (already_visited(ny,nx,nd)) continue;

      if (!is_wall(ny,nx)) {
        dist[ny][nx] = nd;
        d.push_front({ ny, nx });
      } else {
        for (int i = -2; i <= 2; i++) {
          for (int j = -2; j <= 2; j++) {
            if (i==0 && j==0) continue;
            int ni = i+y;
            int nj = j+x;

            if (!is_range(ni,nj)) continue;
            if (is_wall(ni,nj)) continue;
            if (already_visited(ni,nj,ndd)) continue;

            dist[ni][nj] = ndd;
            d.push_back({ ni, nj });
          }
        }
      }
    }
  }
}

int main() {
  IOS;
  cin >> h >> w;
  cin >> ch >> cw;
  cin >> dh >> dw;
  REP(i,h) cin >> s[i];
  ch--; cw--; dh--; dw--;
  REP(i,1010) REP(j,1010) dist[i][j] = INF;
  dist[ch][cw] = 0;

  bfs();

  if (dist[dh][dw] != INF) {
    COUT(dist[dh][dw]);
    return 0;
  }

  COUT(-1);
  return 0;
}
