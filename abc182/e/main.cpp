#include <bits/stdc++.h>
using namespace std;
#define ALL(x) (x).begin(),(x).end()
#define COUT(x) cout<<(x)<<"\n"
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define REP(i,n) for(int i=0;i<n;i++)
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
template<class T>bool chmax(T &a,const T &b) {if(a<b){a=b; return 1;} return 0;}
template<class T>bool chmin(T &a,const T &b) {if(b<a){a=b; return 1;} return 0;}
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;


const int MX = 1500;
const pair<int, int> direction[4] = {
  { -1, 0 }, { 1, 0 }, { 0, -1 }, { 0, 1 }
};

int h,w,n,m;

bool light[MX][MX];
bool wall[MX][MX];
bool ok[MX][MX];

bool visited[MX][MX];
bool memo[MX][MX];

bool f(int d, int i, int j) {
  if (i < 0 || j < 0 || h <= i || w <= j) return false;
  if (wall[i][j]) return false;
  if (light[i][j]) return true;
  if (visited[i][j]) return memo[i][j];

  visited[i][j] = true;
  int ni = i + direction[d].first;
  int nj = j + direction[d].second;

  return memo[i][j] = f(d, ni, nj);
}

int main() {
  IOS;
  cin >> h >> w >> n >> m;
  REP(i,n) {
    int a,b; cin >> a >> b;
    a--; b--; light[a][b] = 1;
  }
  REP(i,m) {
    int c,d; cin >> c >> d;
    c--; d--; wall[c][d] = 1;
  }

  REP(d,4) {
    REP(i,h) REP(j,w) visited[i][j] = 0;
    REP(i,h) REP(j,w) if(f(d,i,j)) ok[i][j] = 1;
  }

  int ans = 0;
  REP(i,h) REP(j,w) ans += ok[i][j];
  COUT(ans);
  return 0;
}