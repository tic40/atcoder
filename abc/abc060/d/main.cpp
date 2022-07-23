#include <bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);i++)
#define endl '\n'

int n,w,w1;
vector<vector<int>> g(4);
int ans = 0;

void dfs(int p, int tw, int tv) {
  if (p == 4) {
    ans = max(ans,tv);
    return;
  }

  dfs(p+1,tw,tv); // w1+p の重さを一つも選択しない
  // 価値が高い順に行けるところまで試す
  for (int v: g[p]) {
    tw += w1+p;
    tv += v;
    if (tw > w) break; // 超過
    dfs(p+1, tw, tv);
  }
  return;
}

int main() {
  cin >> n >> w;
  REP(i,n) {
    int a,b; cin >> a >> b;
    if (i == 0) w1 = a;
    g[a-w1].push_back(b);
  }
  // 重さごとに価値が高い順にソート
  REP(i,4) sort(g[i].rbegin(),g[i].rend());

  dfs(0,0,0);
  cout << ans << endl;
  return 0;
}