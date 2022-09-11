#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'
using P = pair<int,int>;

const vector<P> moves = { {1,0}, {-1,0}, {0,1}, {0,-1} };
int n,k;

int dfs(vector<string> s, int cnt) {
  if (cnt == k) return 1;

  REP(i,n) REP(j,n) {
    if (s[i][j] != '.') continue;

    bool ok = (cnt == 0);
    if (!ok) {
      for(auto [x,y]: moves) {
        int ni = i+x, nj = j+y;
        if (ni < 0 || nj < 0 || ni >= n || nj >= n) continue;
        if (s[ni][nj] == '@') ok = true;
      }
    }

    if (ok) {
      int res = 0;
      s[i][j] = '@';
      res += dfs(s,cnt+1);
      s[i][j] = '#';
      res += dfs(s,cnt);
      return res;
    }
  }

  return 0;
}

int main() {
  cin >> n >> k;
  vector<string> s(n);
  REP(i,n) cin >> s[i];

  cout << dfs(s,0) << endl;
  return 0;
}