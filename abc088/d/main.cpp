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

const vector<P> moves = { {-1,0},{1,0},{0,-1},{0,1} };

int main() {
  IOS;
  int h,w; cin>>h>>w;
  char s[h][w];
  int white=0;
  REP(i,h) REP(j,w) {
    cin>>s[i][j];
    if (s[i][j] == '.') white++;
  }

  int dist[h][w]; memset(dist, -1, sizeof(dist));
  dist[0][0] = 0;
  queue<P> q;
  q.push({0,0});

  while(!q.empty()) {
    auto v = q.front(); q.pop();
    int y = v.first, x = v.second;

    for(auto d: moves) {
      int ny = v.first+d.first, nx = v.second+d.second;

      if (ny < 0 || nx < 0 || ny >= h || nx >= w) continue;
      if (s[ny][nx] == '#') continue;
      if (dist[ny][nx] != -1) continue;

      dist[ny][nx] = dist[y][x]+1;
      q.push({ny, nx});
    }
  }

  if (dist[h-1][w-1] == -1) { COUT(-1); return 0; }
  COUT(max(0, white - (dist[h-1][w-1] + 1)));
  return 0;
}
