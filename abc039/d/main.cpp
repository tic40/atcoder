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

int h,w;
vector<string> s(100);
int memo[100][100];
const vector<P> moves = {
  {-1, -1},
  {-1, 0},
  {-1, 1},
  {0, -1},
  {0, 1},
  {1, -1},
  {1, 0},
  {1, 1},
};

bool is_range(int x, int y) {
  return 0 <= x && x < w && 0 <= y && y < h;
}

bool possible(int i, int j) {
  if (s[i][j] != '#') return false;

  for (P p: moves) {
    int x = j+p.first;
    int y = i+p.second;
    if (!is_range(x,y)) continue;
    if (s[y][x] != '#') return false;
  }
  return true;
}

void paint_black(int i, int j) {
  memo[i][j] = 1;
  for (P p: moves) {
    int x = j+p.first;
    int y = i+p.second;
    if (!is_range(x,y)) continue;
    if (memo[y][x] == 0) memo[y][x] = 2;
  }
}

void solve() {
  REP(i,h) REP(j,w) {
    if (s[i][j] == '#') {
      if (memo[i][j] == 0) { COUT("impossible"); return; }
    }
  }

  COUT("possible");

  REP(i,h) {
    REP(j,w) cout << (memo[i][j] == 1 ? '#' : '.');
    cout << endl;
  }
}

int main() {
  IOS;
  cin >> h >> w;
  REP(i,h) cin >> s[i];

  REP(i,h) REP(j,w) {
    if (possible(i,j)) paint_black(i,j);
  }
  solve();

  return 0;
}