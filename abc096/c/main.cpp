#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for(int i = 0; i < n; i++)
#define COUT(x) cout<<(x)<<endl
#define dump(x)  cout << #x << " = " << (x) << endl;
using ll = long long;
using P = pair<int,int>;
using Graph = vector<vector<int>>;
using M = map<int,int>;
using PQ = priority_queue<int>;
using PQG = priority_queue<int, vector<int>, greater<int>>;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LINF = 1e18;

char g[55][55];
vector<P> dir = { {1,0},{-1,0},{0,1},{0,-1} };

int main() {
  int h,w; cin>>h>>w;
  REP(i,h) REP(j,w) { cin >> g[i+1][j+1]; }

  for (int i = 1; i<=h; i++) {
    for (int j = 1; j<=w; j++) {
      if (g[i][j] != '#') continue;
      int ok = 0;
      for (auto x: dir) {
        ok = ok || g[i+x.first][j+x.second] == '#';
      }
      if (!ok) { COUT("No"); return 0; }
    }
  }
  COUT("Yes");
  return 0;
}