#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<n;i++)
#define endl '\n'
using ll = long long;
const ll LINF = 1e18;

int main() {
  vector a(3,vector<int>(3));
  REP(i,3) REP(j,3) cin >> a[i][j];

  // used[i][j] := takahashi が置いたときは 1, aoki が置いたときは -1
  vector used(3,vector<int>(3));
  // マス{i,j}にターン t が置いたとき、タテ・ヨコ・ナナメいずれかが揃って勝てるか？
  auto win = [&](int i, int j, int t) {
    int res = 0, s = 3*t;
    used[i][j] = t;
    REP(i,3) res |= used[i][0] + used[i][1] + used[i][2] == s;
    REP(j,3) res |= used[0][j] + used[1][j] + used[2][j] == s;
    res |= used[0][0] + used[1][1] + used[2][2] == s;
    res |= used[0][2] + used[1][1] + used[2][0] == s;
    used[i][j] = 0;

    return res;
  };

  auto dfs = [&](auto self, int cnt, ll score) -> ll {
    if (cnt == 9) return score;
    // takahashi のターンは 1, aoki のターンは -1
    int t = cnt % 2 ? -1 : 1;

    ll res = -t*LINF;
    REP(i,3) REP(j,3) {
      if (used[i][j] != 0) continue; // 既に使われている
      if (win(i,j,t)) return t*LINF; // 3マス揃って勝てる場合

      used[i][j] = t;
      res = (t == 1) ?
        max(res,self(self,cnt+1,score+a[i][j]))
        : min(res,self(self,cnt+1,score-a[i][j]));
      used[i][j] = 0;
    }
    return res;
  };

  ll ans = dfs(dfs,0,0);
  cout << (ans > 0 ? "Takahashi" : "Aoki") << endl;
  return 0;
}