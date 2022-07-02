#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
using ll = long long;

int n;
vector<vector<int>> a;
ll ans = 0;

const vector<pair<int,int>> moves = {
  { -1, -1 }, { 0, -1 }, { 1, -1 },
  { -1, 0 }, { 1, 0 }, { 1, 1 },
  { 0, 1 }, { -1, 1 }
};

void dfs(int i, int j, int cnt, int dir, ll now) {
  if (cnt == n) { ans = max(ans,now); return; }

  auto [ti,tj] = moves[dir];
  int ni = ti+i;
  int nj = tj+j;
  if (ni == -1) ni = n-1;
  if (nj == -1) nj = n-1;
  if (ni == n) ni = 0;
  if (nj == n) nj = 0;

  ll v = now * 10 + a[ni][nj];
  dfs(ni, nj, cnt+1, dir, v);
  return;
}

int main() {
  cin >> n;
  a.resize(n,vector<int> (n));
  REP(i,n) {
    string s; cin >> s;
    REP(j,n) a[i][j] = s[j]-'0';
  }

  REP(i,n) REP(j,n) {
    REP(d,8) dfs(i,j,1,d,a[i][j]);
  }

  cout << ans << endl;
  return 0;
}