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

int main() {
  IOS;
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector<vector<int>> ver(h+1,vector<int>(w+1)), hor(h+1,vector<int>(w+1));

  REP(i,h) REP(j,w) {
    if (s[i][j] == '#') continue;
    ver[i+1][j+1] = ver[i][j+1]+1;
    hor[i+1][j+1] = hor[i+1][j]+1;
  }

  for (int i = h; i > 0; i--) {
    for (int j = w; j > 0; j--) {
      if (ver[i-1][j-1] == 0) continue;
      chmax(ver[i-1][j-1], ver[i][j-1]);
      chmax(hor[i-1][j-1], hor[i-1][j]);
    }
  }

  int ans = 1;
  REP(i,h) REP(j,w) {
    chmax(ans, ver[i+1][j+1]+hor[i+1][j+1]-1);
  }
  COUT(ans);
  return 0;
}
