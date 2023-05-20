#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using P = pair<int,int>;
const string snk = "snuke";
const vector<P> d = {{1,-1},{1,0},{1,1},{0,-1},{0,1},{-1,-1},{-1,0},{-1,1}};

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  auto f = [&](int i, int j, P dir) {
    auto [di,dj] = dir;
    vector<P> ans;
    REP(k,5) {
      if (i < 0 || j < 0 || i >= h || j >= w) return;
      if (s[i][j] != snk[k]) return;
      ans.emplace_back(i,j);
      i += di, j += dj;
    }
    for(auto [x,y]: ans) cout << x+1 << " " << y+1 << endl;
  };

  REP(i,h) REP(j,w) REP(k,8) f(i,j,d[k]);
  return 0;
}