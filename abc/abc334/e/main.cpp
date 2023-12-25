#include <bits/stdc++.h>
#include <atcoder/all>
using namespace atcoder;
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using mint = modint998244353;

const vector<int> di = { 0,0,1,-1 };
const vector<int> dj = { 1,-1,0,0 };

int main() {
  int h,w; cin >> h >> w;
  vector<string> s(h);
  REP(i,h) cin >> s[i];

  vector id(h,vector<int>(w));
  auto dfs = [&](auto self, int i, int j, int col) -> void {
    id[i][j] = col;
    REP(k,4) {
      int ni = i+di[k], nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (s[ni][nj] == '.') continue;
      if (id[ni][nj] != 0) continue;
      self(self,ni,nj,col);
    }
  };
  int col = 0;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '.' || id[i][j] != 0) continue;
    col++;
    dfs(dfs,i,j,col);
  }

  mint sum = 0, cnt = 0;
  REP(i,h) REP(j,w) {
    if (s[i][j] == '#') continue;
    set<int> st;
    REP(k,4) {
      int ni = i+di[k], nj = j+dj[k];
      if (ni < 0 || nj < 0 || ni >= h || nj >= w) continue;
      if (id[ni][nj] == 0) continue;
      st.insert(id[ni][nj]);
    }
    sum += col - st.size() + 1;
    cnt++;
  }

  mint ans = sum / cnt;
  cout << ans.val() << endl;

  return 0;
}