#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;

int main() {
  vector a(3,vector<int>(3));
  REP(i,3) REP(j,3) cin >> a[i][j];

  vector b(3,vector<int>(3));
  auto win = [&](int i, int j, int t) {
    int s = 3*t;
    b[i][j] = t;
    bool res = false;
    REP(i,3) if (b[i][0] + b[i][1] + b[i][2] == s) res = true;
    REP(j,3) if (b[0][j] + b[1][j] + b[2][j] == s) res = true;
    if (b[0][0] + b[1][1] + b[2][2] == s) res = true;
    if (b[0][2] + b[1][1] + b[2][0] == s) res = true;
    b[i][j] = 0;

    return res;
  };

  auto dfs = [&](auto self, int cnt, ll score, int t) -> ll {
    if (cnt == 9) return score;

    ll res = -t*LINF;
    REP(i,3) REP(j,3) {
      if (b[i][j] != 0) continue;
      if (win(i,j,t)) return t*LINF;

      b[i][j] = t;
      if (t == 1) res = max(res,self(self,cnt+1,score+a[i][j],-t));
      else res = min(res,self(self,cnt+1,score-a[i][j],-t));
      b[i][j] = 0;
    }
    return res;
  };

  ll ans = dfs(dfs,0,0,1);
  cout << (ans > 0 ? "Takahashi" : "Aoki") << endl;
  return 0;
}